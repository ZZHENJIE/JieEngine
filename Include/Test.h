#pragma once

#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

class Test : public JEEntity{
public:
    Test(){
        this->GetComponent<JETransform>().Position = {200.0f,150.0f};
        this->AddComponent<JEPhysics>({
            JECreateRectBody({20,20},b2_dynamicBody,this,{0.3f,0.3f,0.5f})
        });
        auto Body = this->GetComponent<JEPhysics>().Body;
        Body->SetTitle("Test");
    }
    ~Test(){
        
    }
private:
    void Update(){

    }

    void Event(SDL_Event Event){

    }
};