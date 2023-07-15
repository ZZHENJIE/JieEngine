#include "../System.h"

void SystemUpdate(std::vector<std::shared_ptr<Entity>> EntityVector){
    if(Rigidbody::EntityID.empty() == false){
        RigidbodySystem(EntityVector);
    }
    if(Mesh::EntityID.empty() == false){
        MeshSystem(EntityVector);
    }
}