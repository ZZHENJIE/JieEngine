#include "GameMap.h"
#include "Entity.h"

using namespace JieEngine;

void GameMap::_MapUpdate(){
    this->Update();
    for(auto Temp : this->EntityManage){
        Temp->Update();
    }
    Resource.SManage->Update(this->EntityManage);
}

void GameMap::_MapEvent(SDL_Event Event){
    this->Event(Event);
    for(auto Temp : this->EntityManage){
        Temp->Event(Event);
    }
}