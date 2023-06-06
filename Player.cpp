#include "Player.h"

void Player::Update(){
    this->UpdateAnimation();
};
const char * Player::GetClass(){
    return "Player";
};