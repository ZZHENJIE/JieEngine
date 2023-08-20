#pragma once

#include "Entity.h"

using namespace JieEngine;

class Player : public Entity {
    public:
        Player(const char * Title):Entity(Title){
            this->AddComponents<Mesh,RigidBody>({
                true,
                nullptr
            },{
                true,
                0,
                0,
                20
            });
            this->GetComponent<Transform>().Size = {20,20};
            this->GetComponent<Transform>().Pos = {130,50};
        }
        Player(Entity * Ptr):Entity(Ptr){
            
        }
        virtual void Update() override{
            
        }
        virtual void Event(SDL_Event Event) override{
            if(Event.key.type == SDL_KEYDOWN){
                switch(Event.key.keysym.sym){
                    case SDLK_a:{
                        this->GetComponent<RigidBody>().XForce -= 10;
                        break;
                    }
                    case SDLK_d:{
                        this->GetComponent<RigidBody>().XForce += 10;
                        break;
                    }
                    case SDLK_w:{
                        this->GetComponent<RigidBody>().YForce += 10;
                        break;
                    }
                }
            }
        }
        void Collide(Entity * Object_1,Entity * Object_2){

        }
};

class Barrier : public Entity{
    public:
        Barrier(const char * Title):Entity(Title){
            this->AddComponent<Mesh>({
                true,
                nullptr
            });
            this->GetComponent<Transform>().Size = {20,20};
        }
        Barrier(Entity * Ptr):Entity(Ptr){
            
        }
        virtual void Update() override{
            
        }
        virtual void Event(SDL_Event Event) override{
            
        }
        void Collide(Entity * Object_1,Entity * Object_2){

        }
};