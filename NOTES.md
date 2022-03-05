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