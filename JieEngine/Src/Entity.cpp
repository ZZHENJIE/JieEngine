#include "Entity.h"
#include "Component.h"

Entity::Entity(){
    this->ID = JieEngine::EntityCountId;
    this->AddComponent(Transform());
    JieEngine::EntityCountId ++;
}

Entity::~Entity(){

}

template<typename T>
void Entity::AddComponent(T component){
    Components[typeid(T).name()] = component;
}

template<typename T>
T & Entity::GetComponent(){
    return std::experimental::any_cast<T&>(Components[typeid(T).name()]);
}

template void Entity::AddComponent(Transform);
template Transform & Entity::GetComponent();

template void Entity::AddComponent(Mesh);
template Mesh & Entity::GetComponent();

template void Entity::AddComponent(Rigidbody);
template Rigidbody & Entity::GetComponent();