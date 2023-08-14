#pragma once

#include "Entity.h"

using namespace JieEngine;

class Player : public Entity {
    public:
        Player(){
            this->Title = "Player";
        }
        Player(Entity * Ptr):Entity(Ptr){
            
        }
        virtual void Update() override{
            
        }
        virtual void Event(SDL_Event Event) override{
            // if(Event.button.type == SDL_MOUSEBUTTONDOWN){
            //     cout << "111" << endl;
            // }
        }
};

