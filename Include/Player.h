#pragma once

#include "Entity.h"

class Player : public Entity {
    public:
        Player();
        void Update() override;
        void Event(SDL_Event Event) override;
};