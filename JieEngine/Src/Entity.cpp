#include "Entity.h"

using namespace JieEngine;

Entity::Entity(const char * Title){
    if(Title == nullptr){
        this->Title = typeid(this).name();
    }else{
        this->Title = Title;
    }
    this->ID = Resource._GenerateEntityID.Push(1);
<<<<<<< HEAD
    this->AddComponent<Transform>({{0,0},{0,0},0});
=======
>>>>>>> 535fbdba87fd472195cd413d29e283c4d4fc2b79
}

Entity::Entity(Entity * Ptr){
    this->Title = Ptr->Title;
    this->ID = Ptr->ID;
    this->Components = Ptr->Components;
}

Entity::~Entity(){
    Resource._GenerateEntityID.Remove(this->ID);
    for(auto Temp : this->Components){
        if(Temp.second.Data.type() != typeid(Transform)){
            ComponentManage::DestroyComponentS(Temp.second);
        }
    }
}
