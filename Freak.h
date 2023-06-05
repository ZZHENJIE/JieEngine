#ifndef FREAK_H
#define FREAK_H

#include "Animal.h"

class Freak : public Animal{
    public:
        Freak(SDL_Rect Position,SDL_Surface * Surface,SDL_Surface * WindowSurface){
            this->Position.x = Position.x;
            this->Position.y = Position.y;
            this->Position.w = Position.w;
            this->Position.h = Position.h;

            this->WindowSurface = WindowSurface;
            this->Surface = Surface;
            this->Speed = 1;
        }
        void Update() override;
};

#endif