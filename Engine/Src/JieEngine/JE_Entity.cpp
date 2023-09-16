#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JEContainer<JEUnInt> JEEntity::EntityIDAssignment = JEContainer<JEUnInt>(-1);

JEEntity::JEEntity(){
    this->ID = EntityIDAssignment.Add(1);
    EntityIDAssignment[this->ID] = this->ID;
    this->_Lock = true;
}

JEEntity::~JEEntity(){
    if(this->_Lock == false){
        this->EntityIDAssignment.Remove(this->ID);
    }
    for(auto Iterate : ComponentList){
        for(auto Component : JEComponentManage::ComponentData){
            if(Iterate == Component.first){
                JEComponentManage::ComponentData.at(Iterate).Destroy(this->ID);
                break;
            }
        }
    }
}

JEUnInt JEEntity::GetID(){
    return this->ID;
}