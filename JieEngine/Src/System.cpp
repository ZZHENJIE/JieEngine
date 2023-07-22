#include "System.h"

using namespace JieEngine;

void SystemManage::Update(EntityManage EntityVector){
    for(auto Function : this->_SystemFunction){
        (*Function.second)(EntityVector);
    }
}