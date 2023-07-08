#pragma once

#include "../JieEngine/GameMap.h"
#include "Player.hpp"

class OneMap : public GameMap{
    void Update(){
        
    }
    void WindowEvent(SDL_Event Event,GameMap *& Present){
        if(Event.button.type == SDL_MOUSEBUTTONDOWN){
            this->EntityVector.push_back(std::make_shared<Player>());
        }
    }
    public:
    ~OneMap(){
        SDL_Log("One Delete");
    }
};