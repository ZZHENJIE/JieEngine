#include "TestMap.h"

void MeshSystem(EntityManage Entity){
    
}

void RigidBodySystem(EntityManage Entity){
    
}

void TransformSystem(EntityManage Entity){
    
}

Player * CreateEntity(){
    Player * Test = new Player();
    Test->AddComponents<Transform,Mesh,RigidBody>({
        true,
        false
    },{
        true,
        false
    },{
        true,
        false
    });
    return Test;
}

void TestMap::Update(){

}

void TestMap::Event(SDL_Event Event){
    if(Event.key.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_d){
        this->AddEntity(CreateEntity());
    }
}