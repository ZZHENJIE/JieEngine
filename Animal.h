#ifndef ANIMAL_H
#define ANIMAL_H

#include "Component.h"
#include "Still.h"

class Animal : public Component{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Animal";
        }
        /*
            每帧更新函数
        */
        virtual void Update() = 0;
        /*
            设置动物移动速度
        */
        void SetMoveSpeed(short Speed){
            this->MoveSpeed = Speed;
        }
        /*
            默认向左移动函数
        */
        virtual void MoveLeft(){
            this->Position.x -= MoveSpeed;
        }
        /*
            默认向右移动函数
        */
        virtual void MoveRight(){
            this->Position.x += MoveSpeed;
        }
        /*
            默认碰撞检测函数
        */
        virtual void Detect(Still still){
            
        }
    protected:
        short MoveSpeed = 3;
};

#endif