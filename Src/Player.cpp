#include "Player.h"

Player::Player(){
    this->AddComponent(Mesh(this->ID));
    this->AddComponent(Rigidbody(this->ID,0,0,5,0.1));
}

void Player::Update(){
    
}
void Player::Event(SDL_Event Event){
    if(Event.key.type == SDL_KEYDOWN){
        switch(Event.key.keysym.sym){
            case SDLK_w:{
                if(this->GetComponent<Rigidbody>().Y == 0){
                    this->GetComponent<Rigidbody>().Y -= 5;
                } 
                break;
            }
            case SDLK_a:{
                this->GetComponent<Rigidbody>().X -= 1;
                break;
            }
            case SDLK_d:{
                this->GetComponent<Rigidbody>().X += 1;
                break;
            }
            case SDLK_e:{
                this->GetComponent<Transform>().Position.y = 100;
                break;
            }
        }
    }
}