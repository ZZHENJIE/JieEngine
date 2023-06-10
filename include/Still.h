#ifndef STILL_H
#define STILL_H

#include "Component.h"
#include "Animation.h"

class Still : public Component{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Still";
        }
        /*
            构造函数 参数为 动画素材路径 动画分割数量 播放速度(数值越大越慢) 显示位置 WindowSurface
        */
        virtual void SetData(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,ImageInciseNumber,PlaySpeed,&this->Position,WindowSurface);
            this->Size = ObjectAnimation->GetComponentSize();
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            构造函数 参数为 图片素材路径 显示位置 WindowSurface
        */
        virtual void SetData(const char * FileUrl,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,&this->Position,WindowSurface);
            this->Size = ObjectAnimation->GetComponentSize();
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            每帧更新函数 记得加 this->ObjectAnimation->Update(); 哦
        */
        virtual void Update() = 0;
        /*
            释放资源函数 记得加 this->ObjectAnimation->Free(); 哦
        */
        virtual void Free() = 0;
};

#endif