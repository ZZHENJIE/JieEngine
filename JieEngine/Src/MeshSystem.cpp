#include "System.h"

using namespace JieEngine;

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    for(auto Iterate : ComponentManage::GetEntityIDJVector<Mesh>()){
        cout << EntityManage[Iterate]->Title << endl;
    }
}

