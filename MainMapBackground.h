#ifndef MAINMAPBACKGROUND_H
#define MAINMAPBACKGROUND_H

#include "JieEngine/MapBackground.h"

class MainMapBackground : public MapBackground{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "MainMapBackground";
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
};

#endif