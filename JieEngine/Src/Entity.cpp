#include "Entity.h"
#include "Component.h"

Entity::Entity(){
    try{
        if(JieEngine::EntityCountId < ENTITY_MAX){
            this->ID = JieEngine::EntityCountId;
            this->AddComponent(new Transform());
            JieEngine::EntityCountId ++;
        }else{
            throw "EntityCount Larger ENTITY_MAX";
        }
    }catch(const char * Msg){
        SDL_Log("Error %s\n",Msg);
    }
}

Entity::~Entity(){
    JieEngine::EntityCountId--;
}

template<typename T>
void Entity::AddComponent(T * component){
    Components[typeid(T).name()] = *component;
}

template<typename T>
T & Entity::GetComponent(){
    return std::experimental::any_cast<T&>(Components[typeid(T).name()]);
}

template void Entity::AddComponent(Transform *);
template Transform & Entity::GetComponent();

template void Entity::AddComponent(Mesh *);
template Mesh & Entity::GetComponent();

template void Entity::AddComponent(Rigidbody *);
template Rigidbody & Entity::GetComponent();