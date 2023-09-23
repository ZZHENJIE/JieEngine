#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

vector<void(*)()> JESystemManage::_FunctionList;

unordered_map<string,void(*)(JEUnInt EntityID)> JESystemManage::_ComponentSystemList;

void JESystemManage::Init(){
    _FunctionList.clear();
    _ComponentSystemList.clear();
}

void JESystemManage::Update(vector<shared_ptr<JEEntity>> EntityManage){
    for(auto Iterate : EntityManage){
        for(auto Component : Iterate->ComponentList){
            if(_ComponentSystemList[Component] != nullptr){
                (*_ComponentSystemList[Component])(Iterate->ID);
            }
        }
    }
    for(auto Iterate : _FunctionList){
        (*Iterate)();
    }
}

void JESystemManage::AddFunction(void(*Function)()){
    _FunctionList.push_back(Function);
}

void JESystemManage::RemoveFunction(void(*Function)()){
    for(auto Iterate = _FunctionList.begin();Iterate != _FunctionList.end();Iterate++){
        if((*Iterate) == Function){
            _FunctionList.erase(Iterate);
            break;
        }
    }
}