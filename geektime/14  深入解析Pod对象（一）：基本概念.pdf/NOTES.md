Pod扮演的是传统部署环境里“虚拟机”的角色。这样的设计，是为了使用户从传统环境（虚拟机环境）向
Kubernetes（容器环境）的迁移，更加平滑。而如果你能把 Pod 看成传统环境里的“机器”、把容器看作是运行在这个“机器”里的“用户程
序”，那么很多关于 Pod 对象的设计就非常容易理解。比如： 凡是调度、网络、存储，以及安全相关的属性，基本上是 Pod 级别的。
这些属性的共同特征是，它们描述的是“机器”这个整体，而不是里面运行的“程序”。比如，配
置这个“机器”的网卡（即：Pod 的网络定义），配置这个“机器”的磁盘（即：Pod 的存储定
义），配置这个“机器”的防火墙（即：Pod 的安全定义）。更不用说，这台“机器”运行在哪个
服务器之上（即：Pod 的调度）。

### 几个Pod字段：
| 字段名                                                       | 作用                                                         | Code snippet                                                 | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| NodeSelector                                                 | 将 Pod 与 Node 进行绑定                                      | ![carbon](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon.svg) | 着这个 Pod 永远只能运行在携带了“disktype: ssd”标签（Label）的节点上；否则，它将调度失败。 |
| NodeName                                                     | 一旦 Pod 的这个字段被赋值，Kubernetes 项目就会被认为这个 Pod 已经经过了调度 |                                                              | 这个字段一般由调度器负责设置，但用户也可以设置它来“骗过”调度器，一般是在测试或者调试的时候才会用到。 |
| HostAliases                                                  | 定义 Pod 的 hosts 文件（比如 /etc/hosts）里的内容            | ![carbon11](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon11.svg) | Pod的host文件将会是这样：![](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon111.svg) |
| shareProcessNamespace                                        | 凡是跟容器的 Linux Namespace 相关的属性，一定是 Pod 级别的，比如shareProcessNamespace | ![carbon (1)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon%20(1).svg) | busybox这个container可以看到nginx  container中的进程：![image-20220307104506788](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/image-20220307104506788.png) |
| 凡是 Pod 中的容器要共享宿主机的 Namespace，也一定是 Pod 级别的定义 | hostNetwork、hostIPC、hostPID等                              | ![carbon (2)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon%20(2).svg) | 共享宿主机的 Network、IPC 和 PID Namespace。这就意味着，这个Pod 里的所有容器，会直接使用宿主机的网络、直接与宿主机进行 IPC 通信、看到宿主机里正在运行的所有进程。 |

