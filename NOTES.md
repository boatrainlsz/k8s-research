kubectl在pod中执行命令
```shell
kubectl exec -it <pod-name> -- <command>
##比如
kubectl exec -it <pod-name> -- /bin/bash
```