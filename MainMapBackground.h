#ifndef MAINMAPBACKGROUND_H
#define MAINMAPBACKGROUND_H

#include "include/MapBackground.h"

class MainMapBackground : public MapBackground{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "MainMapBackground";
        }
        /*
            构造函数 参数为 WindowSurface
        */
        MainMapBackground(SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
        }
        /*
            每帧更新函数
        */
        void Update(){
            
        }
        /*
            接收事件 除了退出事件 其它事件都接收的到
        */
        void WindowEvent(SDL_Event Event){
            
        }
        /*
            释放资源函数
        */
        void Free(){

        }

};

#endif