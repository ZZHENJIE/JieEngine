#pragma once

#include "GameMap.h"
#include "JieEngine.h"
#include "Player.h"
#include <iostream>

using namespace std;
using namespace JieEngine;

class TestMap : public GameMap{
    public:
        TestMap(){
            
        }
        virtual void Update() override;
        virtual void Event(SDL_Event Event) override;
};