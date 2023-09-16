#pragma once

#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

class Barrier : public JEEntity{
public:
    Barrier(){
        this->AddComponent<JEPhysics>({
            JECreateRectBody({150,150},{10,10},b2_staticBody,this->GetID())
        });
        this->GetComponent<JEPhysics>().Body->SetTitle("Rect");
    }
    ~Barrier(){

    }
private:
    void Update(){

    }

    void Event(SDL_Event Event){
        if(Event.key.type == SDL_KEYDOWN){
            if(Event.key.keysym.sym == SDLK_x){
                
            }
        }
    }
};