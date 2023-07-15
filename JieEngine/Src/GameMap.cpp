#include "../GameMap.h"

GameMap::GameMap(){
    JieEngine::EntityCountId = 0;
    Mesh::EntityID.clear();
    Rigidbody::EntityID.clear();
    this->EntityVector.clear();
}

GameMap::~GameMap(){
    
}

void GameMap::ChangeGameMap(GameMap *& Present,GameMap * Future){
    Present = nullptr;
    Present = Future;
}

void GameMap::MapUpdate(){
    Uint8 R,G,B,A;
    SDL_Rect Window = {0,0,JieEngine::WindowSize.w,JieEngine::WindowSize.h};
    SDL_GetRenderDrawColor(JieEngine::WindowRenderer,&R,&G,&B,&A);
    SDL_SetRenderDrawColor(JieEngine::WindowRenderer,0,0,0,255);
    SDL_RenderFillRect(JieEngine::WindowRenderer,&Window);
    SDL_SetRenderDrawColor(JieEngine::WindowRenderer,R,G,B,A);
    this->Update();
    for(auto Temp : this->EntityVector){
        Temp.get()->Update();
    }
    SystemUpdate(this->EntityVector);
}

void GameMap::MapWindowEvent(SDL_Event Event,GameMap *& Present){
    this->WindowEvent(Event,Present);
    for(auto Temp = this->EntityVector.begin();Temp != this->EntityVector.end(); Temp++){
        Temp.base()->get()->Event(Event);
    }
}

void GameMap::SetCameraBindEntity(Entity * BindEntity){
    this->CameraPosition = &BindEntity->GetComponent<Transform>().Position;
}