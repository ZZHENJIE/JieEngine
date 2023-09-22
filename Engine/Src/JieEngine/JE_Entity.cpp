#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JEContainer<JEUnInt> JEEntity::EntityIDAssignment = JEContainer<JEUnInt>(-1);

JEEntity::JEEntity(){
    this->ID = EntityIDAssignment.Add(1);
    EntityIDAssignment[this->ID] = this->ID;
    this->AddComponent<JETransform>({{0,0},0.0f});
    this->_Lock = true;
}

JEEntity::JEEntity(JEEntity * Ptr){
    this->ComponentList = Ptr->ComponentList;
    this->ID = Ptr->ID;
    this->_Lock = Ptr->_Lock;
}

JEEntity::~JEEntity(){
    if(this->_Lock == false){
        this->EntityIDAssignment.Remove(this->ID);
        for(auto Iterate : ComponentList){
            if(JEComponentManage::_ComponentData.at(Iterate).Destroy != nullptr){
                JEComponentManage::_ComponentData.at(Iterate).Destroy(this->ID);
            }
        }
    }
}

JEUnInt JEEntity::GetID(){
    return this->ID;
}