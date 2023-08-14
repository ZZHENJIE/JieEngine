#include "TestMap.h"

<<<<<<< HEAD
TestMap::TestMap(){
    Player * Temp = new Player("Player");
    this->AddEntity<Player>(Temp);
    Barrier * Barrier1 = new Barrier("Barrier1");
    Barrier * Barrier2 = new Barrier("Barrier2");
    Barrier * Barrier3 = new Barrier("Barrier3");
    Barrier * Barrier4 = new Barrier("Barrier4");
    Barrier * Barrier5 = new Barrier("Barrier5");
    Barrier1->GetComponent<Transform>().Pos = {100,100};
    Barrier2->GetComponent<Transform>().Pos = {120,120};
    Barrier3->GetComponent<Transform>().Pos = {140,120};
    Barrier4->GetComponent<Transform>().Pos = {160,120};
    Barrier5->GetComponent<Transform>().Pos = {160,100};
    this->AddEntity<Barrier>(Barrier1);
    this->AddEntity<Barrier>(Barrier2);
    this->AddEntity<Barrier>(Barrier3);
    this->AddEntity<Barrier>(Barrier4);
    this->AddEntity<Barrier>(Barrier5);
}

=======
>>>>>>> 535fbdba87fd472195cd413d29e283c4d4fc2b79
void TestMap::Update(){
    
}

void TestMap::Event(SDL_Event Event){
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_m){
        Barrier * Temp = new Barrier("Barrier");
        this->AddEntity<Barrier>(Temp);
    }
}