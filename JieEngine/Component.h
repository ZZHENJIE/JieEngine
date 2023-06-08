#ifndef COMPONENT_H
#define COMPONENT_H

#include "JieEngine.h"
#include "Animation.h"

class Component : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Component";
        }
        /*
            每帧更新函数
        */
        virtual void Update() = 0;
        /*
            释放资源函数 记得加 this->ObjectAnimation->Free(); 哦
        */
        virtual void Free() = 0;

        SDL_Point Position;
        SDL_Point Size;
    protected:
        Animation * ObjectAnimation;
};

#endif