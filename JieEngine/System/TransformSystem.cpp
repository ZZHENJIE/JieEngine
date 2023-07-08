#include "../System.h"

void TransformSystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Temp : Transform::EntityComponent){
        SDL_Log("System-%d\n",EntityVector[Temp].get()->GetComponent<Transform>().Position.x);
    }
}