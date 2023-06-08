#ifndef MAP_H
#define MAP_H

#include "JieEngine.h"
#include "MapBackground.h"
#include "MapStruct.h"

class Map : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Map";
        }
        /*
            构造函数 参数为 地图背景类 地图结构类 WindowSurface
        */
        Map(MapBackground * Mapbackground,MapStruct * Mapstruct,SDL_Surface * WindowSurface){
            this->Mapbackground = Mapbackground;
            this->Mapstruct = Mapstruct;
            this->WindowSurface = WindowSurface;
        }
        /*
            接收事件 除了退出事件 其它事件都接收的到
        */
        void WindowEvent(SDL_Event Event){
            this->Mapbackground->WindowEvent(Event);
            this->Mapstruct->WindowEvent(Event);
        };
        /*
            每帧更新函数
        */
        void Update(){
            this->Mapbackground->Update();
            this->Mapstruct->Update();
        };
        /*
            释放资源函数
        */
        void Free (){
            this->Mapbackground->Free();
            this->Mapstruct->Free();
        }
    private:
        MapBackground * Mapbackground;
        MapStruct * Mapstruct;
};

#endif