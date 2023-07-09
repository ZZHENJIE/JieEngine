#include "../System.h"

void SystemUpdate(std::vector<std::shared_ptr<Entity>> EntityVector){
    if(Rigidbody::EntityComponent.empty() == false){
        RigidbodySystem(EntityVector);
    }
    if(Mesh::EntityComponent.empty() == false && Mesh::EntityComponent.size() > 1){
        MeshSystem(EntityVector);
    }
}