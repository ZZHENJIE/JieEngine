#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include <iostream>

class Component
{
    protected:
        SDL_Rect Position;
        SDL_Surface * WindowSurface;
        SDL_Surface * ImageSurface;
        short ImageInciseNumber,PlaySpeed;
    public:
        ~Component(){
            SDL_FreeSurface(this->WindowSurface);
        }
        SDL_Rect * GetPos(){
            return &Position;
        }
        virtual void Update(){
            
        };
};

#endif