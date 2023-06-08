#ifndef UI_H
#define UI_H

#include "JieEngine.h"

class Ui : public JieEngine{
    public:
        /*
            获取类名 后期更好对 对象进行一个判断 JieEngine 每个类都有这个函数
        */
        virtual const char * GetClass(){
            return "Ui";
        }
        
        SDL_Point Position;
        SDL_Point Size;
};

#endif