//
// Created by luosizhi on 2022/3/10.
//
#define STACK_SIZE (1024 * 1024)
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>


static char container_stack[STACK_SIZE];

char *const container_args[] = {
        "/bin/bash",
        NULL
};

int container_main(void *args) {
    printf("Container - inside the container! \n");
    //https://man7.org/linux/man-pages/man2/mount.2.html
    //https://unix.stackexchange.com/questions/136646/what-is-type-none-for-mount-points-and-why-are-mount-points-of-the-same-type-b
    mount("none", "/tmp", "tmpfs", 0, "");
    execv(container_args[0], container_args);
    printf("Something is wrong! \n");
    return 1;
}

int main(){
    printf("Parent - start a container! \n");
    int container_pid = clone(container_main, container_stack + STACK_SIZE, CLONE_NEWNS | SIGCHLD, NULL);
    printf("Container - container pid is %d \n", container_pid);
    waitpid(container_pid, NULL, 0);
    printf("Parent - container exited! \n");
    return 0;
}