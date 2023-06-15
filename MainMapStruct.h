#ifndef MAINMAPSTRUCT_H
#define MAINMAPSTRUCT_H

#include "Include/MapStruct.h"
#include "TestMapStruct.h"

class MainMapStruct : public MapStruct{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "MainMapStruct";
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
            if(Event.button.clicks == 1){
                MWindowMapStruct->Free();
                MWindowMapStruct = new TestMapStruct();
            }
        }
        /*
            释放资源函数
        */
        void Free(){

        }
};

#endif