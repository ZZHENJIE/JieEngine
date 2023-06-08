#ifndef JIEENGINE_H
#define JIEENGINE_H

#define WINDOW_W 600
#define WINDOW_H 500

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class JieEngine{
    public:
        /*
            获取类名 后期更好对 对象进行一个判断 JieEngine 每个类都有这个函数
        */
        virtual const char * GetClass(){
            return "JieEngine";
        }
        /*
            WindowSurface 因为SDL内每添加一个东西到屏幕上都必须要有 WindowSurface
        */
        SDL_Surface * WindowSurface;
        /*
            一个函数即可设置SDL_Rect的值 减少代码重复 更简洁
        */
        static void SetRectInfo(SDL_Rect * Rect,int x,int y, int w,int h){
            Rect->x = x;
            Rect->y = y;
            Rect->w = w;
            Rect->h = h;
        }
        /*
            打印出SDL_Rect的数据 用于测试
        */
        static void PrintRectInfo(SDL_Rect * Rect){
            cout << "JieEngine: X:" << Rect->x << " Y:" << Rect->y << " W:" << Rect->w << " H:" << Rect->h << endl;
        }
};

#endif