#include "Entity.h"

using namespace JieEngine;

Entity::Entity(){
    this->ID = Resource._GenerateEntityID.Push(1);
}

Entity::Entity(Entity *& Ptr){
    this->ID = Ptr->ID;
    this->Components = Ptr->Components;
}

Entity::~Entity(){
    Resource._GenerateEntityID.Remove(this->ID);
    for(auto Temp : this->Components){
        ComponentManage::DestroyComponentS(Temp.second);
    }
}
