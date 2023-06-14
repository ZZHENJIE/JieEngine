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
            设置WindowSurface
        */
        void SetWindowSurface(SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
        }
        /*
            每帧更新函数
        */
        virtual void Update() = 0;
        /*
            释放资源函数
        */
        virtual void Free() = 0;
};

#endif