#ifndef PLAYER_H
#define PLAYER_H

#include "Animal.h"

class Player : public Animal{
    public:
        Player(const char * FileUrl,SDL_Point Position,short ImageInciseNumber,short PlaySpeed,SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
            this->ImageSurface = SDL_LoadBMP(FileUrl);
            
            this->Position = Position;

            this->ImageInciseNumber = ImageInciseNumber;
            this->PlaySpeed = PlaySpeed;

            this->InciseImage();
        }

        void Update() override;
        const char * GetClass() override;
};


#endif