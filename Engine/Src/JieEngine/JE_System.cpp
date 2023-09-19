#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

vector<void(*)(JEUnInt EntityID)> JESystemManage::_FunctionList;

unordered_map<string,void(*)(JEUnInt EntityID)> JESystemManage::_ComponentSystem;

void JESystemManage::Init(){
    _FunctionList.clear();
    _ComponentSystem.clear();
}

void JESystemManage::Update(vector<shared_ptr<JEEntity>> EntityManage){
    for(auto Iterate : EntityManage){
        for(auto Component : Iterate->ComponentList){
            if(_ComponentSystem[Component] != nullptr){
                (*_ComponentSystem[Component])(Iterate->ID);
            }
        }
    }
    for(auto Iterate : _FunctionList){
        for(auto EntityID : EntityManage){
            (*Iterate)(EntityID->ID);
        }
    }
}

void JESystemManage::AddFunction(void(*Function)(JEUnInt EntityID)){
    _FunctionList.push_back(Function);
}

void JESystemManage::RemoveFunction(void(*Function)(JEUnInt EntityID)){
    for(auto Iterate = _FunctionList.begin();Iterate != _FunctionList.end();Iterate++){
        if((*Iterate) == Function){
            _FunctionList.erase(Iterate);
            break;
        }
    }
}