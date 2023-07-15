#pragma once

#include "../JieEngine/Entity.h"

class Player : public Entity {
    public:
        Player(){
            this->AddComponent(Mesh(this->ID));
            this->AddComponent(Rigidbody(this->ID));
        }
        void Update(){
            
        }
        void Event(SDL_Event Event){
            if(Event.key.type == SDL_KEYDOWN){
                switch(Event.key.keysym.sym){
                    case SDLK_w:{
                        this->GetComponent<Rigidbody>().Y += 10;
                        break;
                    }
                    case SDLK_a:{
                        this->GetComponent<Rigidbody>().X -= 10;
                        break;
                    }
                    case SDLK_d:{
                        this->GetComponent<Rigidbody>().X += 10;
                        break;
                    }
                }
            }
        }
};