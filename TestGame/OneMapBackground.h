#ifndef ONEMAPBACKGROUND_H
#define ONEMAPBACKGROUND_H

#include "../MapBackground.h"

class OneMapBackground :public MapBackground{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "OneMapBackground";
        }
        /*
            构造函数
        */
        OneMapBackground(const char * ImageUrl,SDL_Surface * WindowSurface);
        /*
            每帧更新函数
        */
        void Update();
        /*
            接收事件 除了退出事件 其它事件都接收的到
        */
        void WindowEvent(SDL_Event Event);
};

#endif