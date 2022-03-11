#define _GNU_SOURCE

#include <fcntl.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE);} while (0)


/**
 * 它一共接收两个参数，第一个参数是 argv[1]，即当前进程要加入的
Namespace 文件的路径，比如 /proc/25686/ns/net；而第二个参数，则是你要在这个
Namespace 里运行的进程，比如 /bin/bash。
 这段代码的的核心操作，则是通过 open() 系统调用打开了指定的 Namespace 文件，并把这个
文件的描述符 fd 交给 setns() 使用。在 setns() 执行后，当前进程就加入了这个文件对应的
Linux Namespace 当中了。

 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    int fd;
    fd = open(argv[1], O_RDONLY);
    if (setns(fd, 0) == -1) {
        errExit("setns");
    }
    execvp(argv[2], &argv[2]);
    errExit("execvp");
}