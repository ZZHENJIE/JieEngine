#ifndef FREAK_H
#define FREAK_H

#include "Animal.h"

class Freak : public Animal{
    public:
        Freak(const char * FileUrl,SDL_Point Position,short ImageInciseNumber,short PlaySpeed,SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
            this->ImageSurface = SDL_LoadBMP(FileUrl);
            
            this->Position = Position;
            
            this->ImageInciseNumber = ImageInciseNumber;
            this->PlaySpeed = PlaySpeed;
            this->InciseImage();
        }
};

#endif