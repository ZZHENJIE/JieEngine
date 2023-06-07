# 杰引擎 JieEngine

![](https://www.libsdl.org/media/SDL_logo.png)

本引擎是使用[SDL2图形库](https://www.libsdl.org/)实现的 只支持2D游戏 运行该项目是示例游戏

引擎渲染主要使用的是 Surface 因为 在SDL2中Surface是使用CPU渲染的 而且只包含像素信息 简洁

## 创作背景
许多C++初学者都知道C++在游戏领域是占据非常重要的位置的,所以初学者也想做一款小游戏 可是用C++官方库 在控制台做游戏 始终不满意 所以想做图形游戏 可是虚幻引擎体积太大了 要学习的东西太多了 可能安装引擎的时候就已经不想学习虚幻了(作者就是这样的😰) 所以我去Bing了一下 看到SDL2图形库感觉不错 就试了试 窗口出现的那一刻可以爽一整天了 可是当我用他开始写游戏时 才知道用图形库写游戏有多么难了而且代码就是💩山 所以萌生了写一下小引擎的想法

## 优点
* 体积小
* 配置简单
* 速度快
* 上手快

## 缺点
* 功能少
* BUG多

## 安装

### Windows
1. 配置Mingw环境 [下载地址](https://github.com/niXman/mingw-builds-binaries/releases)
2. 配置SDL2环境 [下载地址](https://github.com/libsdl-org/SDL/releases)
3. 安装Cmake [下载地址](https://cmake.org/download/)
4. Clone该项目 然后直接Cmake编译运行 看看示例游戏能不能跑起来

### Ubuntu
1. 安装GCC G++ 使用该命令 `sudo apt-get install gcc & sudo apt-get install g++`
2. 安装SDL2开发环境 使用该命令 `sudo apt-get install libsdl2-2.0 & sudo apt-get install libsdl2-dev`
3. 安装Cmake 使用该命令 `sudo apt-get install cmake`
4. Clone该项目 然后直接Cmake编译运行 看看示例游戏能不能跑起来