#include "System.h"

using namespace JieEngine;

SystemManage::SystemManage(){
    ComponentManage::EnrollComponent<Mesh>();
    ComponentManage::EnrollComponent<RigidBody>();
    this->EnrollReviseSystem<Mesh>(MeshSystem);
    this->EnrollReviseSystem<RigidBody>(RigidBodySystem);
}

void SystemManage::Update(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Function : this->_SystemFunction){
        (*Function.second)(EntityVector);
    }
}