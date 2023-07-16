# 杰引擎 JieEngine

![](https://raw.githubusercontent.com/ZZHENJIE/JieEngine-TestGame/master/Resource/Logo.png)

![](https://www.libsdl.org/media/SDL_logo.png)

本引擎是使用[SDL2图形库](https://www.libsdl.org/)实现的 只支持2D游戏 使用渲染器渲染画面

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
2. 配置SDL2环境 可以选择[打包好的SDL2环境](https://zhongzhenjie.lanzoum.com/i4syo0yvw7sd)或自己下载配置
    * SDL2本体[下载地址](https://github.com/libsdl-org/SDL/releases)
    * SDL2-Mixer[下载地址](https://github.com/libsdl-org/SDL_mixer/releases)
    * SDL2-Image[下载地址](https://github.com/libsdl-org/SDL_image/releases)
    * SDL2-TTF[下载地址](https://github.com/libsdl-org/SDL_ttf/releases)
3. 安装Cmake [下载地址](https://cmake.org/download/)
5. 然后直接Cmake编译运行 看看能不能跑起来

### Ubuntu 22.04
1. 安装GCC G++ 使用该命令 `sudo apt-get install gcc g++`
2. 安装SDL2开发环境 使用该命令 `sudo apt-get install libsdl2-2.0 libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev libsdl2-ttf-dev`
3. 安装Cmake 使用该命令 `sudo apt-get install cmake`
5. 然后直接Cmake编译运行 看看能不能跑起来

### MacOS
1. 安装brew
    * 常规安装脚本（推荐 完全体 几分钟安装完成
        `/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"`
    * 极速安装脚本（精简版 几秒钟安装完成
        `/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)" speed`
2. 检查电脑是否有G++ GCC 编译器 `g++ -v Or gcc -v` 如果有大量的字符串输出证明电脑有G++ GCC
3. 安装SDL2开发环境 使用该命令 `brew install sdl2 sdl2_mixer sdl2_image sdl2_ttf`
4. 安装Cmake 使用该命令 `brew install cmake`
5. 然后直接Cmake编译运行 看看能不能跑起来

## [示例游戏](https://github.com/ZZHENJIE/JieEngine-TestGame)

## [文档](https://zzhenjie.github.io/JieEngine-Document/#/)