#pragma once

#include "../JieEngine/GameMap.h"
#include "Player.hpp"
#include "Barrier.hpp"

class OneMap : public GameMap{
public:
    OneMap(){
        auto Entity1 = std::make_shared<Player>();
        Entity1.get()->GetComponent<Transform>().Position = {100,100};
        Entity1.get()->GetComponent<Transform>().Size = {100,100};
        auto Entity2 = std::make_shared<Barrier>();
        Entity2.get()->GetComponent<Transform>().Position = {200,200};
        Entity2.get()->GetComponent<Transform>().Size = {100,100};
        auto Entity3 = std::make_shared<Barrier>();
        Entity3.get()->GetComponent<Transform>().Position = {220,200};
        Entity3.get()->GetComponent<Transform>().Size = {100,100};
        this->EntityVector.push_back(Entity1);
        this->EntityVector.push_back(Entity2);
        this->EntityVector.push_back(Entity3);
        SDL_SetRenderDrawColor(JieEngine::WindowRenderer,255,255,240,200);
    }
    void Update(){
        
    }
    void WindowEvent(SDL_Event Event,GameMap *& Present){

    }
};