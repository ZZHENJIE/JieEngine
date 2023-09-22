# JieEngine

## 简介

一个简单的2D C++游戏引擎 物理引擎采用[Box2D](https://box2d.org)

<img src="https://zzhenjie.github.io/JieEngine-Document/Docs/Image/Logo.svg" style="width: 10%;">

<img src="https://box2d.org/images/logo.svg" style="width: 10%;">

## 优点

* 体积小
* 配置简单
* 速度快
* 上手快

## 缺点

* 功能少
* BUG多

## 常见问题

**如果编译能通过但是VSCODE一直报未找到头文件错误,可以使用以下方法**

`Ctrl + Shift + P` 打开VSCODE Command Palette 输入 `C/C++:Edit Configurations (JSON)` 会在文件夹内自动创建一个JSON文件 找到`includePath`这个数组 把头文件路径填写上去就好了 例如:

```json
"includePath": [
    "${workspaceFolder}/JieEngine/Include/",
    "${workspaceFolder}/Test/Include/"
]
```

## [文档](https://www.jieengine.cn)