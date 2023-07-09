#include "../Entity.h"

Entity::Entity(){
    this->ID = JieEngine::EntityCountId;
    JieEngine::EntityCountId ++;
}

Entity::~Entity(){

}