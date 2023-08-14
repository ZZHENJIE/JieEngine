#include "System.h"

using namespace JieEngine;

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
<<<<<<< HEAD
    EntityIDJVector EntityId = ComponentManage::GetEntityIDJVector<Mesh>();
    for(int i = 0; i < EntityId.Size; i++){
        std::shared_ptr<Entity> Object1 = EntityManage[EntityId.Begin[i]];
        
=======
    for(auto Temp : EntityManage){
        cout << Temp->Title << endl;
>>>>>>> 535fbdba87fd472195cd413d29e283c4d4fc2b79
    }
}

