#include "System.h"

using namespace JieEngine;

void SystemManage::Update(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Function : this->_SystemFunction){
        (*Function.second)(EntityVector);
    }
}