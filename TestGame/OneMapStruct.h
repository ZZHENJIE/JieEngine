#ifndef ONEMAPSTRUCT_H
#define ONEMAPSTRUCT_H

#include "../MapStruct.h"

class OneMapStruct :public MapStruct{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "OneMapstruct";
        }
        /*
            构造函数
        */
        OneMapStruct(SDL_Surface * WindowSurface);
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