#include "GameMap.h"
#include "Entity.h"

using namespace JieEngine;

GameMap::GameMap(){
    this->EntityManage.resize(10);
}

void GameMap::_MapUpdate(){
    Uint8 R,G,B,A;
    SDL_GetRenderDrawColor(Resource.WindowRender,&R,&G,&B,&A);
    SDL_SetRenderDrawColor(Resource.WindowRender,0,0,0,255);
    SDL_RenderPresent(Resource.WindowRender);
    SDL_RenderClear(Resource.WindowRender);
    SDL_SetRenderDrawColor(Resource.WindowRender,R,G,B,A);
    this->Update();
    for(auto Iterate : this->EntityManage){
        if(Iterate != nullptr){
            Iterate->Update();
        }
    }
    Resource.SManage->Update(this->EntityManage);
}

void GameMap::_MapEvent(SDL_Event Event){
    this->Event(Event);
    for(auto Iterate : this->EntityManage){
        if(Iterate != nullptr){
            Iterate->Event(Event);
        }
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
        if(Iterate != nullptr){
            if(strcmp(Iterate->Title,Title) == 0){
                return Iterate;
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Entity> GameMap::GetEntity(string Title){
    for(auto Iterate : this->EntityManage){
        if(Iterate != nullptr){
            if(strcmp(Iterate->Title,Title.c_str()) == 0){
                return Iterate;
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Entity> GameMap::GetEntity(int EntityID){
    return this->EntityManage[EntityID];
}