#include "System.h"

using namespace JieEngine;

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    EntityIDJVector EntityId = ComponentManage::GetEntityIDJVector<Mesh>();
    for(int i = 0; i < EntityId.Size; i++){
        std::shared_ptr<Entity> Object1 = EntityManage[EntityId.Begin[i]];
        
    }
}

