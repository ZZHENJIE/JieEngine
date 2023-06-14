#ifndef MAPSTRUCT_H
#define MAPSTRUCT_H

#include "JieEngine.h"

class MapStruct : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "MapStruct";
        }
        /*
            设置WindowSurface
        */
        void SetWindowSurface(SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
        }
        /*
            改变地图结构函数 (不能使用)
        */
        void Change_MapStruct(MapStruct * This,MapStruct * Mapstruct){
            This = Mapstruct;
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
    private:
};

#endif 