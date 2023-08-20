#include "Entity.h"

using namespace JieEngine;

Entity::Entity(const char * Title){
    if(Title == nullptr){
        this->Title = typeid(this).name();
    }else{
        this->Title = Title;
    }
    this->ID = Resource._GenerateEntityID.Add(1);
    this->Components[typeid(Transform).name()].Data = Transform({{0,0},{0,0},0});
}

Entity::Entity(Entity * Ptr){
    this->Title = Ptr->Title;
    this->ID = Ptr->ID;
    this->Components = Ptr->Components;
}

int Entity::GetID(){
    return this->ID;
}

Entity::~Entity(){
    Resource._GenerateEntityID.Remove(this->ID);
    for(auto Iterate : this->Components){
        if(Iterate.second.Data.type() != typeid(Transform)){
            ComponentManage::DestroyComponent(Iterate.second);
        }
    }
}
