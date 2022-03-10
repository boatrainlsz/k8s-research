#### 什么是挂载？

https://unix.stackexchange.com/questions/3192/what-is-meant-by-mounting-a-device-in-linux

#### Mount Namespace

Mount Namespace 修改的，是容器进程对文件系统“挂载点”的认知。

Mount Namespace 跟其他 Namespace 的使用略有不同的地方：它对容器进程视图的改变，一定是伴随着挂载操作（mount）才能生效。



#### 没有灵魂的rootfs 

需要明确的是，只是一个操作系统所包含的文件、配置和目录，并不包括操作系统内核。在 Linux 操作系统中，这两部分是分开存放的，操作系统只有在开机启动时才会加载指定版本的内核镜像。实际上，同一台机器上的所有容器，都共享宿主机操作系统的内核。



#### docker的增量rootfs

```shell
docker run -d ubuntu:latest sleep 3600
docker image inspect ubuntu:latest
```



使用联合文件系统将这些层挂载到一个统一的挂载点(/var/lib/docker/aufs/mnt/)上：

