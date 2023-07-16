#include "OneMap.h"

OneMap::OneMap(){
    auto Entity1 = std::make_shared<Player>();
    Entity1.get()->GetComponent<Transform>().Position = {100,100};
    Entity1.get()->GetComponent<Transform>().Size = {40,40};
    auto Entity2 = std::make_shared<Barrier>();
    Entity2.get()->GetComponent<Transform>().Position = {100,200};
    Entity2.get()->GetComponent<Transform>().Size = {20,20};
    auto Entity3 = std::make_shared<Barrier>();
    Entity3.get()->GetComponent<Transform>().Position = {120,200};
    Entity3.get()->GetComponent<Transform>().Size = {20,20};
    auto Entity4 = std::make_shared<Barrier>();
    Entity4.get()->GetComponent<Transform>().Position = {140,200};
    Entity4.get()->GetComponent<Transform>().Size = {20,20};
    auto Entity5 = std::make_shared<Barrier>();
    Entity5.get()->GetComponent<Transform>().Position = {80,180};
    Entity5.get()->GetComponent<Transform>().Size = {20,20};
    auto Entity6 = std::make_shared<Barrier>();
    Entity6.get()->GetComponent<Transform>().Position = {160,180};
    Entity6.get()->GetComponent<Transform>().Size = {20,20};
    this->EntityVector.push_back(Entity1);
    this->EntityVector.push_back(Entity2);
    this->EntityVector.push_back(Entity3);
    this->EntityVector.push_back(Entity4);
    this->EntityVector.push_back(Entity5);
    this->EntityVector.push_back(Entity6);
    SDL_SetRenderDrawColor(JieEngine::WindowRenderer,255,255,240,200);
    Mesh::DeBug = true;
    this->SetFocusEntity(Entity1.get()->ID);
}

void OneMap::Update(){
        
}
void OneMap::WindowEvent(SDL_Event Event,GameMap *& Present){

}