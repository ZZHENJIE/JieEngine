#pragma once

#include "JieEngine.h"
#include "Player.h"

using namespace JieEngine;

class TestMap : public GameMap{
    public:
<<<<<<< HEAD
        TestMap();
=======
        TestMap(){
            
        }
>>>>>>> 535fbdba87fd472195cd413d29e283c4d4fc2b79
        virtual void Update() override;
        virtual void Event(SDL_Event Event) override;
};