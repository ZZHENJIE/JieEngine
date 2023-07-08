#pragma once

#include "../JieEngine/Entity.h"
#include "../JieEngine/Component.h"

class Player : public Entity {
    public:
        Player(){
            this->AddComponent(Transform(this->ID));
        }
        void Update(){
            
        }
        void Event(SDL_Event Event){

        }
};