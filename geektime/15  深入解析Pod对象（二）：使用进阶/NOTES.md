### 投射数据卷（Projected Volume）
| 类型                | 作用                                                         |
| ------------------- | ------------------------------------------------------------ |
| Secret              | 把 Pod 想要访问的加密数据，存放到 Etcd 中。然后，你就可以通过在 Pod 的容器里挂载 Volume 的方式，访问到这些 Secret里保存的信息了。 |
| ConfigMap           | 一旦 Pod 的这个字段被赋值，Kubernetes 项目就会被认为这个 Pod 已经经过了调度 |
| Downward API        | 定义 Pod 的 hosts 文件（比如 /etc/hosts）里的内容            |
| ServiceAccountToken | 凡是跟容器的 Linux Namespace 相关的属性，一定是 Pod 级别的，比如shareProcessNamespace |

