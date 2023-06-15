#ifndef TESTMAPSTRUCT_H
#define TESTMAPSTRUCT_H

#include "Include/MapStruct.h"

class TestMapStruct : public MapStruct{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "TestMapStruct";
        }
        /*
            每帧更新函数
        */
        void Update(){

        }
        /*
            接收事件 除了退出事件 其它事件都接收的到
        */
        void WindowEvent(SDL_Event Event,MapStruct * MWindowMapStruct){
             
        }
        /*
            释放资源函数
        */
        void Free(){

        }
};

#endif