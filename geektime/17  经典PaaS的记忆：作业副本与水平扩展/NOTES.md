### Deployment与ReplicaSet、Pod的关系

![How Kubernetes Deployments Work – The New Stack](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/07751442-deployment.png)

Deployment 同样通过“控制器模式”，来操作 ReplicaSet 的个数和属性，进而实现“水平扩展 / 收缩”和“滚动更新”这两个编排动作。

水平扩展 / 收缩：控制ReplicaSet 的Pod的个数。

滚动更新：创建新的ReplicaSet，常用来进行版本升级，如下：

![image-20220307145237719](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/image-20220307145237719.png)

Deployment 控制 ReplicaSet（版本），ReplicaSet 控制 Pod（副本数）。这个两层控制关系一定要牢记。