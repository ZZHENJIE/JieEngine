#include "Player.h"

void Player::Update(){
    SDL_FillRect(this->Surface,&this->Position,0xff);
}