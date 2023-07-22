#include "OneMap.h"

OneMap::OneMap(){
    auto Entity1 = std::make_shared<Player>();
    Entity1.get()->GetComponent<Transform>().Position = {90,20};
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
    auto Entity7 = std::make_shared<Barrier>();
    Entity7.get()->GetComponent<Transform>().Position = {140,110};
    Entity7.get()->GetComponent<Transform>().Size = {20,20};
    Entity7.get()->AddComponent(new Rigidbody(Entity7.get()->ID,0,0,3,0.9));
    this->EntityVector.push_back(Entity1);
    this->EntityVector.push_back(Entity2);
    this->EntityVector.push_back(Entity3);
    this->EntityVector.push_back(Entity4);
    this->EntityVector.push_back(Entity5);
    this->EntityVector.push_back(Entity6);
    this->EntityVector.push_back(Entity7);
    SDL_SetRenderDrawColor(JieEngine::WindowRenderer,255,255,240,200);
    Mesh::DeBug = true;
    this->SetFocusEntity(Entity1.get()->ID);
}

void OneMap::Update(){
        
}
void OneMap::WindowEvent(SDL_Event Event,GameMap *& Present){

}