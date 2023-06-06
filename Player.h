#ifndef PLAYER_H
#define PLAYER_H

#include "Animal.h"

class Player : public Animal{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Player";
        }
        /*
            构造函数 参数为 动画素材路径 动画分割数量 播放速度(数值越大越慢) 显示位置 WindowSurface
        */
        Player(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,ImageInciseNumber,PlaySpeed,Position,WindowSurface);
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            构造函数 参数为 图片素材路径 显示位置 WindowSurface
        */
        Player(const char * FileUrl,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,Position,WindowSurface);
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            每帧更新函数
        */
        void Update(){
            this->ObjectAnimation->Update();
        }
};

#endif