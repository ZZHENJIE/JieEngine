#ifndef BARRIER_H
#define BARRIER_H

#include "../Still.h"

class Barrier : public Still{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Barrier";
        }
        
        void Update(){
            this->ObjectAnimation->Update();
            if(this->Position.x <= 0){
                this->Position.x = WINDOW_W;
                this->Position.y = rand() % (WINDOW_H - Size.y);
            }
            this->Position.x --;
        }
};

#endif