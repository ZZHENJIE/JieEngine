#pragma once

#include "Entity.h"

class Barrier : public Entity {
    public:
        Barrier();
        void Update();
        void Event(SDL_Event Event);
};