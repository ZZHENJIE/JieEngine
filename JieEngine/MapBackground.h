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
            释放资源函数
        */
        virtual void Free() = 0;
};

#endif