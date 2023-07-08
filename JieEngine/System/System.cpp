#include "../System.h"

void SystemUpdate(std::vector<std::shared_ptr<Entity>> EntityVector){
    if(Mesh::EntityComponent.empty() == false){
        MeshSystem(EntityVector);
    }
}