#include "../GameMap.h"

GameMap::GameMap(){
    JieEngine::EntityCountId = 0;
    Mesh::EntityID.clear();
    Rigidbody::EntityID.clear();
    this->EntityVector.clear();
    this->FocusObjectID = -1;
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
    if(this->FocusObjectID != -1){
        Transform & FocusObjectTransform = this->EntityVector[this->FocusObjectID].get()->GetComponent<Transform>();
        SDL_Point Distance = {
            (JieEngine::WindowSize.w/2 - FocusObjectTransform.Size.w/2) - FocusObjectTransform.Position.x,
            (JieEngine::WindowSize.h/2 - FocusObjectTransform.Size.h/2) - FocusObjectTransform.Position.y
        };
        for(auto Temp : this->EntityVector){
            Transform & EntityTransform = Temp.get()->GetComponent<Transform>();
            EntityTransform.Position.x += Distance.x;
            EntityTransform.Position.y += Distance.y;
        }
    }
}

void GameMap::MapWindowEvent(SDL_Event Event,GameMap *& Present){
    this->WindowEvent(Event,Present);
    for(auto Temp = this->EntityVector.begin();Temp != this->EntityVector.end(); Temp++){
        Temp.base()->get()->Event(Event);
    }
}

void GameMap::SetFocusEntity(signed int BindEntityID){
    FocusObjectID = BindEntityID;
}