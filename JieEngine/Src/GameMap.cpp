#include "../GameMap.h"

GameMap::GameMap(){
    JieEngine::EntityCountId = 0;
    Transform::EntityComponent.clear();
    Mesh::EntityComponent.clear();
    this->EntityVector.clear();
}

GameMap::~GameMap(){
    
}

void GameMap::ChangeGameMap(GameMap *& Present,GameMap * Future){
    Present = nullptr;
    Present = Future;
}

void GameMap::MapUpdate(){
    this->Update();
    for(auto Temp = this->EntityVector.begin();Temp != this->EntityVector.end(); Temp++){
        Temp.base()->get()->Update();
    }
    SystemUpdate(this->EntityVector);
}

void GameMap::MapWindowEvent(SDL_Event Event,GameMap *& Present){
    this->WindowEvent(Event,Present);
    for(auto Temp = this->EntityVector.begin();Temp != this->EntityVector.end(); Temp++){
        Temp.base()->get()->Event(Event);
    }
}