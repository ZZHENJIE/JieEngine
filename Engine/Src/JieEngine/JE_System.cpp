#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JESystem::JESystem(){
    this->_FunctionList.clear();
}

void JESystem::Update(){
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