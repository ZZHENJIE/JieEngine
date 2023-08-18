#include "GameMap.h"
#include "Entity.h"

using namespace JieEngine;

void GameMap::_MapUpdate(){
    this->Update();
    for(auto Iterate : this->EntityManage){
        Iterate->Update();
    }
    Resource.SManage->Update(this->EntityManage);
}

void GameMap::_MapEvent(SDL_Event Event){
    this->Event(Event);
    for(auto Iterate : this->EntityManage){
        Iterate->Event(Event);
    }
}

void GameMap::RemoveEntity(Entity * Type){
    this->EntityManage[Type->ID] = nullptr;
}

void GameMap::RemoveEntity(int EntityID){
    this->EntityManage[EntityID] = nullptr;
}

std::shared_ptr<Entity> GameMap::GetEntity(const char * Title){
    for(auto Iterate : this->EntityManage){
        if(strcmp(Iterate->Title,Title) == 0){
            return Iterate;
        }
    }
    return nullptr;
}

std::shared_ptr<Entity> GameMap::GetEntity(string Title){
    for(auto Iterate : this->EntityManage){
        if(strcmp(Iterate->Title,Title.c_str()) == 0){
            return Iterate;
        }
    }
    return nullptr;
}

std::shared_ptr<Entity> GameMap::GetEntity(int EntityID){
    return this->EntityManage[EntityID];
}