#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JEContainer<JEUnInt> JEEntity::EntityIDAssignment = JEContainer<JEUnInt>(-1);

JEEntity::JEEntity(){
    this->ID = EntityIDAssignment.Add(1);
}

JEEntity::~JEEntity(){
    this->EntityIDAssignment.Remove(this->ID);
}

JEUnInt JEEntity::GetID(){
    return this->ID;
}