#ifndef ANIMAL_H
#define ANIMAL_H

#include "Component.h"
#include "Still.h"

class Animal : public Component{
    protected:
        SDL_Surface * Surface;
        short Speed;
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
    public:
        ~Animal(){
            SDL_FreeSurface(Surface);
        };
        void Move(int Direction){
            switch(Direction){
                case 0:{
                    Up();
                    break;
                }
                case 1:{
                    Down();
                    break;
                }
                case 2:{
                    Left();
                    break;
                }
                case 3:{
                    Right();
                    break;
                }
            }
        }
        void Detect(Still still){
            
        }
};

#endif