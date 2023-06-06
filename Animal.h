#ifndef ANIMAL_H
#define ANIMAL_H

#include "Component.h"
#include "Still.h"

class Animal : public Component{
    protected:
        short Speed = 3;
    public:
        void Move(int Direction){
            switch(Direction){
                case 0:{
                    Up();
                    break;
                }
                case 1:{
                    Left();
                    break;
                }
                case 2:{
                    Right();
                    break;
                }
            }
        }
        void Detect(Still still){

        }
        const char * GetClass() override{
            return "Animal";
        }
        virtual void Up(){
            this->Position.y -= Speed;
        }
        virtual void Down(){
            this->Position.y += Speed;
        }
        virtual void Left(){
            this->Position.x -= Speed;
        }
        virtual void Right(){
            this->Position.x += Speed;
        }
};

#endif