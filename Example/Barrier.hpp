#pragma once

#include "../JieEngine/Entity.h"

class Barrier : public Entity {
    public:
        Barrier(){
            this->AddComponent(Transform(this->ID));
            this->AddComponent(Mesh(this->ID));
        }
        void Update(){
            SDL_Rect Pos = {
                this->GetComponent<Transform>().Position.x,
                this->GetComponent<Transform>().Position.y,
                this->GetComponent<Transform>().Size.w,
                this->GetComponent<Transform>().Size.h
            };
            SDL_RenderDrawRect(JieEngine::WindowRenderer,&Pos);
        }
        void Event(SDL_Event Event){
            
        }
};