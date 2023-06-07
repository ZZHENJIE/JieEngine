#include "Player.h"

Player::Player(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point Position,SDL_Surface * WindowSurface){
    this->SetData(FileUrl,ImageInciseNumber,PlaySpeed,Position,WindowSurface);
    this->MoveSpeed = 15;
}

Player::Player(const char * FileUrl,SDL_Point Position,SDL_Surface * WindowSurface){
    this->SetData(FileUrl,Position,WindowSurface);
}

void Player::Jump(){
    this->Position.y -= MoveSpeed;
}

void Player::MoveRight(){
    this->Position.x += MoveSpeed;
}

void Player::MoveLeft(){
    this->Position.x -= MoveSpeed;
}

void Player::Update(){
    this->ObjectAnimation->Update();
    this->Position.y ++;
}

void Player::Collide(Component * component,SDL_Rect CollideRect,short CollidePosition){}