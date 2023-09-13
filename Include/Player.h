#pragma once

#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

class Player : public JEEntity{
public:
    Player(){
        this->AddComponent<JEPhysics>({
            JECreateCircleBody({150.0f,100.0f},10.0f,b2_dynamicBody,{0.3f,0.3f,0.5f})
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
                    b2Vec2 force(-500.0f,0.0f);
                    auto Physics = this->GetComponent<JEPhysics>();
                    Physics.Body->ApplyLinearImpulse(force, Physics.Body->GetWorldCenter(), true);
                    break;
                }
                case SDLK_d:{
                    b2Vec2 force(500.0f,0.0f);
                    auto Physics = this->GetComponent<JEPhysics>();
                    Physics.Body->ApplyLinearImpulse(force, Physics.Body->GetWorldCenter(), true);
                    break;
                }
                case SDLK_w:{
                    b2Vec2 force(0.0f,5000.0f);
                    auto Physics = this->GetComponent<JEPhysics>();
                    Physics.Body->ApplyLinearImpulse(force, Physics.Body->GetWorldCenter(), true);
                    break;
                }
                case SDLK_s:{
                    b2Vec2 force(0.0f,-1000.0f);
                    auto Physics = this->GetComponent<JEPhysics>();
                    Physics.Body->ApplyLinearImpulse(force, Physics.Body->GetWorldCenter(), true);
                    break;
                }
                case SDLK_x:{
                    this->RemoveComponent<JEPhysics>();
                    break;
                }
            }
        }
    }
};