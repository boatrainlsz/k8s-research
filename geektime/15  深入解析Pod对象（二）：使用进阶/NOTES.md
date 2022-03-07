### 投射数据卷（Projected Volume）
| 类型                | 作用                                                         | 说明                                                         |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Secret              | 把 Pod 想要访问的加密数据，存放到 Etcd 中。然后，你就可以通过在 Pod 的容器里挂载 Volume 的方式，访问到这些 Secret里保存的信息了。 | 着这个 Pod 永远只能运行在携带了“disktype: ssd”标签（Label）的节点上；否则，它将调度失败。 |
| ConfigMap           | 一旦 Pod 的这个字段被赋值，Kubernetes 项目就会被认为这个 Pod 已经经过了调度 | 这个字段一般由调度器负责设置，但用户也可以设置它来“骗过”调度器，一般是在测试或者调试的时候才会用到。 |
| Downward API        | 定义 Pod 的 hosts 文件（比如 /etc/hosts）里的内容            | Pod的host文件将会是这样：![](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon111.svg) |
| ServiceAccountToken | 凡是跟容器的 Linux Namespace 相关的属性，一定是 Pod 级别的，比如shareProcessNamespace | busybox这个container可以看到nginx  container中的进程：![image-20220307104506788](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/image-20220307104506788.png) |

