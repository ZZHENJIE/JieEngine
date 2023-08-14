#pragma once

#include "JieEngine.h"
#include "Player.h"

using namespace JieEngine;

class TestMap : public GameMap{
    public:
        TestMap();
        virtual void Update() override;
        virtual void Event(SDL_Event Event) override;
};