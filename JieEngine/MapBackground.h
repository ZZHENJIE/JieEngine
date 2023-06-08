#ifndef MAPBACKGROUND_H
#define MAPBACKGROUND_H

#include "JieEngine.h"

class MapBackground : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "MapBackground";
        }
        /*
            每帧更新函数
        */
        virtual void Update() = 0;
        /*
            接收事件 除了退出事件 其它事件都接收的到
        */
        virtual void WindowEvent(SDL_Event Event) = 0;
        /*
            释放资源函数
        */
        virtual void Free() = 0;
};

#endif