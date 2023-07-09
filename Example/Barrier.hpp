#pragma once

#include "../JieEngine/Entity.h"

class Barrier : public Entity {
    public:
        Barrier(){
            this->AddComponent(Transform(this->ID));
            this->AddComponent(Mesh(this->ID));
        }
        void Update(){
            
        }
        void Event(SDL_Event Event){
            
        }
};