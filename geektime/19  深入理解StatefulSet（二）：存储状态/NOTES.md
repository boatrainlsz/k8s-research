开发人员用PersistentVolumeClaim，运维人员声明PersistentVolume。PersistentVolumeClaim是接口，PersistentVolume是实现，开发人员不用去熟悉底层存储配置，只需要声明：我需要多大的存储、它的属性是什么。k8s会将符合条件的PV与PVC绑定。

#### 第一步：运维人员声明一个PV

![carbon (4)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/202203081333241.svg)

#### 第二步：开发人员声明一个PVC



![carbon (1)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/202203081322376.svg)

#### 第二步：开发人员在应用的 Pod 中，声明使用这个 PVC：

![carbon (3)](https://raw.githubusercontent.com/boatrainlsz/my-image-hosting/main/202203081329100.svg)