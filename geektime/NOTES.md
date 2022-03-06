1. kubectl在pod中执行命令

```shell
kubectl exec -it <pod-name> -- <command>
##比如
kubectl exec -it <pod-name> -- /bin/bash
```

2. kubectl增改文件

```shell
kubectl apply -f <file>
```

3. kubectl删除

```shell
kubectl delete -f <file>
```

4. volumes是pod级别的，容器通过volumeMounts挂载到pod中
5. 为什么需要pod，而不是容器？

    因为需要描述一种多容器协同合作的环境，典型地，比如sidecar模式，一个应用+一个日志sidecar。把 Pod 看成传统环境里的“机器”、把容器看作是运行在这个“机器”里的“用户程
   序”，那么很多关于 Pod 对象的设计就非常容易理解