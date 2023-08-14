#include "System.h"

using namespace JieEngine;

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    for(auto Temp : EntityManage){
        cout << Temp->Title << endl;
    }
}

