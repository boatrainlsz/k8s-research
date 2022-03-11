1. 制作[Dockerfile](../../demo/geektime07/Dockerfile)

   ![carbon](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/202203111444693.svg)

2. docker build && run
   ```shell
   docker build -t helloworld .
   docker run -p 4000:80 helloworld
   ```

#### docker exec 原理

就是加入了另一个进程的namespace，见：[setns.c](../../demo/geektime07/setns.c)

