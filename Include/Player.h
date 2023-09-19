#pragma once

#include "JieEngine/JE_Entity.h"
#include "Two.h"

using namespace JieEngine;

class Player : public JEEntity{
public:
    Player(){
        this->AddComponent<JEPhysics>({
            JECreateCircleBody({150.0f,100.0f},10.0f,b2_dynamicBody,this->GetID(),{0.3f,0.3f,0.5f})
        });
        this->GetComponent<JEPhysics>().Body->SetCollideFunction([](b2Body * MainBody,b2Body * DeputyBody){
            
        });
        unordered_map<string,JEAnimationImage> Image;
        JECreateAnimationImage("Player",4,&Image["None"]);
        Image["None"].PlaySpeed = 1000;
        this->AddComponent<JEAnimation>({
            Image,
            "None",
            true
        });
    }

    ~Player(){

    }
private:
    void Update(){
        b2Vec2 Temp = this->GetComponent<JEPhysics>().Body->GetPosition();
        SDL_RenderDrawPointF(Resource._Renderer,Temp.x,-1 * Temp.y);
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
                    this->GetComponent<JEAnimation>().Enabled = !this->GetComponent<JEAnimation>().Enabled;
                    break;
                }
            }
        }
    }
};