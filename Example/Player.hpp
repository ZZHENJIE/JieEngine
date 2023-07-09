#pragma once

#include "../JieEngine/Entity.h"

class Player : public Entity {
    public:
        Player(){
            this->AddComponent(Transform(this->ID));
            this->AddComponent(Mesh(this->ID));
            this->AddComponent(Rigidbody(this->ID));
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
            switch(Event.key.keysym.sym){
                case SDLK_w:{
                    this->GetComponent<Rigidbody>().Up += 10;
                    break;
                }
                case SDLK_s:{
                    this->GetComponent<Rigidbody>().Down += 10;
                    break;
                }
                case SDLK_a:{
                    this->GetComponent<Rigidbody>().Left += 10;
                    break;
                }
                case SDLK_d:{
                    this->GetComponent<Rigidbody>().Right += 10;
                    break;
                }
            }
        }
};