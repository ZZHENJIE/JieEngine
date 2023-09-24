# JieEngine

## 简介

一个简单的2D C++游戏引擎 物理引擎采用[Box2D](https://box2d.org)

<img src="https://www.jieengine.cn/Docs/Image/Logo.svg" style="width: 10%;">

<img src="https://box2d.org/images/logo.svg" style="width: 10%;">

## 创作背景

许多C++初学者都知道C++在游戏领域是占据非常重要的位置的,所以初学者也想做一款小游戏,可是用C++官方库在控制台做游戏始终不满意.所以想做图形游戏,可是虚幻引擎体积太大了,要学习的东西太多了,可能安装引擎的时候就已经不想学习虚幻了(作者就是这样的😰).所以我去Bing了一下,看到SDL2图形库感觉不错,就试了试,窗口出现的那一刻可以爽一整天了.可是当我用他开始写游戏时,才知道用图形库写游戏有多么难了而且代码就是💩山,所以萌生了写一下小引擎的想法.

## 优点

* 使用ECS架构
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
    "${workspaceFolder}/Engine/Include/",
    "${workspaceFolder}/Include/"
]
```

## [文档](https://www.jieengine.cn/)