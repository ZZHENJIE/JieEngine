#pragma once

#include "GameMap.h"
#include "Player.h"
#include "Barrier.h"

class OneMap : public GameMap{
public:
    OneMap();
    void Update() override;
    void WindowEvent(SDL_Event Event,GameMap *& Present) override;
};