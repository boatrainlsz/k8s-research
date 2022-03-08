DaemonSet 的主要作用，是让你在 Kubernetes 集群里，运行一个 Daemon
Pod。 所以，这个 Pod 有如下三个特征：
1. 这个 Pod 运行在 Kubernetes 集群里的每一个节点（Node）上；
2. 每个节点上只有一个这样的 Pod 实例；
3. 当有新的节点加入 Kubernetes 集群后，该 Pod 会自动地在新节点上被创建出来；而当旧
   节点被删除后，它上面的 Pod 也相应地会被回收掉。

常用来
1. 收集每个node的日志
2. 监控每个node的状态
3. 为每个node安装网络插件等等

它的原理就是：通过 nodeAffinity 和 Toleration 这两个调度器的小功能，保证了每个节点上有且只有一个 Pod
