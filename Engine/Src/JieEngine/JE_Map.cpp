#include "JieEngine/JE_Map.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JEMap::JEMap(){
    JEEntity::EntityIDAssignment.Clear();
}

JEMap::~JEMap(){
    for(auto Iterate : JEComponentManage::ComponentData){
        Iterate.second.Data.clear();
    }
}

void JEMap::RemoveEntity(JEUnInt EntityID){
    for (auto Iterate = this->EntityManage.begin(); Iterate != this->EntityManage.end(); Iterate++) {
        if ((*Iterate)->GetID() == EntityID) {
            this->EntityManage.erase(Iterate);
            break;
        }
    }
}

void JEMap::_MapUpdate(){
    Uint8 R,G,B,A;
    SDL_GetRenderDrawColor(Resource._Renderer,&R,&G,&B,&A);
    SDL_SetRenderDrawColor(Resource._Renderer,0,0,0,255);
    SDL_RenderClear(Resource._Renderer);
    SDL_SetRenderDrawColor(Resource._Renderer,R,G,B,A);
    this->Update();
    for(auto Iterate : this->EntityManage){
        if(Iterate != nullptr){
            Iterate->Update();
        }
    }
}

void JEMap::_MapEvent(SDL_Event Event){
    this->Event(Event);
    for(auto Iterate : this->EntityManage){
        if(Iterate != nullptr){
            Iterate->Event(Event);
        }
    }
}