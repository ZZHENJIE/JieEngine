#pragma once

#include "Entity.h"

class Barrier : public Entity {
    public:
        Barrier();
        ~Barrier();
        void Update() override;
        void Event(SDL_Event Event) override;
};