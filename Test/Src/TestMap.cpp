#include "TestMap.h"

void MeshSystem(EntityVector EntityManage){
    for(auto Temp : EntityManage){
        cout << Temp->Title << endl;
    }
}

void RigidBodySystem(EntityVector EntityManage){
    
}

void TestMap::Update(){

}

void TestMap::Event(SDL_Event Event){
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_d){
        Player * Temp = new Player();
        Temp->AddComponent<Mesh>({
            false,
            nullptr
        });
        this->AddEntity<Player>(Temp);
    }
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_a){
        this->EntityManage.pop_back();
    }
}