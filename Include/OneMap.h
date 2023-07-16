#pragma once

#include "GameMap.h"
#include "Player.h"
#include "Barrier.h"

class OneMap : public GameMap{
public:
    OneMap();
    void Update();
    void WindowEvent(SDL_Event Event,GameMap *& Present);
};