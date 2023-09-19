#pragma once

#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

class Barrier : public JEEntity{
public:
    Barrier(){
        this->AddComponent<JEPhysics>({
            JECreateRectBody({150,150},{20,20},b2_staticBody,this->GetID())
        });
        this->GetComponent<JEPhysics>().Body->SetTitle("Rect");
    }
    ~Barrier(){

    }
private:
    void Update(){
        b2Vec2 Temp = this->GetComponent<JEPhysics>().Body->GetPosition();
        SDL_RenderDrawPointF(Resource._Renderer,Temp.x,-1 * Temp.y);
    }

    void Event(SDL_Event Event){

    }
};