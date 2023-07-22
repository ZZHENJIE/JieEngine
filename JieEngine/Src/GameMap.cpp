#include "GameMap.h"

using namespace JieEngine;

void GameMap::_MapUpdate(){
    this->Update();
    for(auto Temp : this->_EntityManage){
        Temp->Update();
    }
    Resource.SManage->Update(this->_EntityManage);
}

void GameMap::_MapEvent(SDL_Event Event){
    this->Event(Event);
    for(auto Temp : this->_EntityManage){
        Temp->Event(Event);
    }
}

void GameMap::AddEntity(Entity * Player){
    this->_EntityManage.push_back(make_shared<Entity>(Player));
}