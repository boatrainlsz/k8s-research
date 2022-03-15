### 网络栈组成

1. 网卡

2. 回环设备

3. 路由表

4. iptables规则

对于一个进程来说，这些要素就构成了它发起和响应网络请求的基本环境。

### 网桥

工作在数据链路层（Data Link），主要功能是根据 MAC 地址学习来将数据包转发到网桥的不同端口（Port）上。



### Veth Pair

它被创建出来后，总是以两张虚拟网卡（Veth Peer）的形式成对出现的。并且，从其中一个“网卡”发出的数据包，可以直接出现在与它对应的另一张“网卡”上，哪怕这两个“网卡”在不同的 Network Namespace 里。这就使得 Veth Pair 常常被用作连接不同 Network Namespace 的“网线”。

### docker网络原理图

![Step-by-Step Guide: Establishing Container Networking - DZone Cloud](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/202203152117240.png)

原理：虚拟网卡插到网桥上后，虚拟网卡就被“剥夺”调用网络协议栈处理数据包的资格，从而“降”成为网桥上的一个端口。而这个端口唯一的作用，就是接收流入的数据包，然后把这些数据包的“生杀大权”（比如转发或者丢弃），全部交给对应的网桥。网桥扮演二层交换机的角色，使用ARP协议获取目的MAC地址，从而将数据包发出去。
