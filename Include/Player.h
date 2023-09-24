#pragma once

#include "JieEngine/JE_Entity.h"
#include "Two.h"

using namespace JieEngine;

class Player : public JEEntity{
public:
    Player(){
        this->GetComponent<JETransform>().Position = {150.0f,100.0f};
        this->AddComponent<JEPhysics>({
            JECreateCircleBody(10.0f,b2_dynamicBody,this->GetID(),{0.3f,0.3f,0.5f})
        });
        this->GetComponent<JEPhysics>().Body->SetCollideFunction([](b2Body * MainBody,b2Body * DeputyBody){
            
        });
        map<string,JEAnimationImage> Image;
        if(JECreateAnimationImage("Player",4,Image["None"]) == SUCCEED){
            Image["None"].PlaySpeed = 1000;
            this->AddComponent<JEAnimation>({
                Image,
                "None",
                true
            });
        }
        JEAudio Audio;
        unordered_map<string,string> AudioFile;
        AudioFile["None"] = "Biu";
        if(JECreateAudio(AudioFile,Audio) == SUCCEED){
            this->AddComponent<JEAudio>(Audio);
        }
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
                case SDLK_x:{
                    auto Audio = this->GetComponent<JEAudio>();
                    Mix_PlayChannel(Audio.Channel,Audio.Sound["None"],0);
                    break;
                }
            }
        }
    }
};