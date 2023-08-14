#include "Component.h"

using namespace JieEngine;

GlobalResourceComponent JieEngine::Resource;

ComponentManage::ComponentManage(){
    this->EnrollComponent<Mesh>();
    this->EnrollComponent<RigidBody>();
    this->EnrollComponent<Transform>();
}