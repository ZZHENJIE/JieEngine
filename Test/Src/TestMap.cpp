#include "TestMap.h"

TestMap::TestMap(){
    Player * Temp = new Player("Player");
    Barrier * Barrier1 = new Barrier("Barrier1");
    Barrier * Barrier2 = new Barrier("Barrier2");
    Barrier * Barrier3 = new Barrier("Barrier3");
    Barrier * Barrier4 = new Barrier("Barrier4");
    Barrier * Barrier5 = new Barrier("Barrier5");
    Barrier1->GetComponent<Transform>().Pos = {100,100};
    Barrier2->GetComponent<Transform>().Pos = {120,120};
    Barrier3->GetComponent<Transform>().Pos = {140,120};
    Barrier4->GetComponent<Transform>().Pos = {160,120};
    Barrier5->GetComponent<Transform>().Pos = {180,100};
    this->AddEntity<Player>(Temp);
    this->AddEntity<Barrier>(Barrier1);
    this->AddEntity<Barrier>(Barrier2);
    this->AddEntity<Barrier>(Barrier3);
    this->AddEntity<Barrier>(Barrier4);
    this->AddEntity<Barrier>(Barrier5);
    SDL_SetRenderDrawColor(Resource.WindowRender,255,255,0,255);
    Mesh::IsDeBug = true;
}

void TestMap::Update(){
    
}

void TestMap::Event(SDL_Event Event){
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_m){
        this->RemoveEntity(this->GetEntity("Barrier3")->GetID());
    }
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_n){
        Barrier * Barrier3 = new Barrier("Barrier3");
        Barrier3->GetComponent<Transform>().Pos = {140,120};
        this->AddEntity<Barrier>(Barrier3);
    }
}