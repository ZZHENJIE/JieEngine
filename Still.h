#ifndef STILL_H
#define STILL_H

#include "Component.h"

class Still : public Component {
    public:
        void SetStill(const char * FileUrl,SDL_Point Position,short ImageInciseNumber,short PlaySpeed,SDL_Surface * WindowSurface){
            this->WindowSurface = WindowSurface;
            this->ImageSurface = SDL_LoadBMP(FileUrl);
            
            this->Position = Position;
            
            this->ImageInciseNumber = ImageInciseNumber;
            this->PlaySpeed = PlaySpeed;
            this->InciseImage();
        }
};

#endif