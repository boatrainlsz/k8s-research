### 投射数据卷（Projected Volume）
| 类型                | 作用                                                         |
| ------------------- | ------------------------------------------------------------ |
| Secret              | 把  想要访问的加密数据，存放到 Etcd 中。然后，你就可以通过在 Pod 的容器里挂载 Volume 的方式，访问到这些 Secret里保存的信息了。 |
| ConfigMap           | 可以理解为未加密的Secret                                     |
| Downward API        | 让 Pod 里的容器能够直接获取到这个 Pod API 对象本身的信息。   |
| ServiceAccountToken | Service Account 的授权信息和文件，保存在它所绑定的一个特殊的 Secret 对象里。这个特殊的 Secret 对象，就叫作ServiceAccountToken。 |

### 容器健康检查和恢复机制

livenessProbe：自定义健康检查

restartPolicy：它是 Pod 的 Spec 部分的一个标准字段（pod.spec.restartPolicy），默认值是 Always，即：任何时候这个容器发生了异常，它一定会被重新创建。

记住两条：

1. 只要 Pod 的 restartPolicy 指定的策略允许重启异常的容器（比如：Always），那么这个 Pod
  就会保持 Running 状态，并进行容器重启。否则，Pod 就会进入 Failed 状态 。
2. 对于包含多个容器的 Pod，只有它里面所有的容器都进入异常状态后，Pod 才会进入 Failed 状
  态。在此之前，Pod 都是 Running 状态。此时，Pod 的 READY 字段会显示正常容器的个数。

readinessProbe：虽然它的用法与 livenessProbe类似，但作用却大不一样。readinessProbe 检查结果的成功与否，决定的这个 Pod 是不是能被通过 Service 的方式访问到，而并不影响 Pod 的生命周期。

### PodPreset（Pod 预设置）

开发人员只需要提交一个基本的、非常简单的 Pod YAML，Kubernetes 就可以自动给对应的 Pod 对象加上其他必要的信息，比如 labels，annotations，volumes 等等。而这些信息，可以是运维人员事先定义好的。这么一来，开发人员编写 Pod YAML 的门槛，就被大大降低了。

开发人员定义的Pod（pod.yaml）：

![carbon (4)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon%20(4).svg)

运维人员定义的Pod（pod-preset.yaml）：

![carbon (5)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/carbon%20(5).svg)

pod-preset.yaml + pod.yaml = 生产可用的Pod：

```shell
 kubectl create -f preset.yaml
 kubectl create -f pod.yaml
 kubectl get pod website -o yaml
```

