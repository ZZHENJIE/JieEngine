#pragma once

#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

class Player : public JEEntity{
public:
    Player(){
        this->GetComponent<JETransform>().Position = {150.0f,100.0f};
        this->AddComponent<JEPhysics>({
            JECreateCircleBody(10.0f,b2_dynamicBody,this,{0.3f,0.3f,0.5f})
        });
        this->GetComponent<JEPhysics>().Body->SetCollideFunction([](b2Body * MainBody,b2Body * DeputyBody){
            
        });
    }
    ~Player(){
    }
private:
    void Update(){
        
    }

    void Event(SDL_Event Event){
        if(Event.key.type == SDL_KEYDOWN){
            switch(Event.key.keysym.sym){
                case SDLK_a:{
                    JEBodyApplyLinearImpulse(this->GetComponent<JEPhysics>().Body,{-500.0f,0.0f});
                    break;
                }
                case SDLK_d:{
                    b2Vec2 force(500.0f,0.0f);
                    JEBodyApplyLinearImpulse(this->GetComponent<JEPhysics>().Body,{500.0f,0.0f});
                    break;
                }
                case SDLK_w:{
                    JEBodyApplyLinearImpulse(this->GetComponent<JEPhysics>().Body,{0.0f,-5000.0f});
                    break;
                }
                case SDLK_s:{
                    JEBodyApplyLinearImpulse(this->GetComponent<JEPhysics>().Body,{0.0f,1000.0f});
                    break;
                }
            }
        }
    }
};