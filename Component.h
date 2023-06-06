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
    protected:
        SDL_Point Position; //控件位置
        SDL_Point Size;     //控件大小
        Animation * ObjectAnimation; //控件动画
};

#endif