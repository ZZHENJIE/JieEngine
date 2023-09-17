#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JESystem::JESystem(){
    this->_FunctionList.clear();
    this->_ComponentSystem.clear();
}

void JESystem::Update(){
    for(auto ComponentData : JEComponentManage::ComponentData){
        if(ComponentData.second.Data.empty() == false && this->_ComponentSystem.at(ComponentData.first) != nullptr){
            for(JEUnInt EntityID = 0; EntityID < ComponentData.second.Data.size();EntityID++){
                if(JEEntity::EntityIDAssignment.At(EntityID) != -1){
                    (*this->_ComponentSystem.at(ComponentData.first))(EntityID);
                }
            }
        }
    }

    for(auto EntityID : JEEntity::EntityIDAssignment){
        for(auto Iterate : this->_FunctionList){
            (*Iterate)(EntityID);
        }
    }
}

void JESystem::AddFunction(void(*Function)(JEUnInt EntityID)){
    this->_FunctionList.push_back(Function);
}

void JESystem::RemoveFunction(void(*Function)(JEUnInt EntityID)){
    for(auto Iterate = this->_FunctionList.begin();Iterate != this->_FunctionList.end();Iterate++){
        if((*Iterate) == Function){
            this->_FunctionList.erase(Iterate);
            break;
        }
    }
}