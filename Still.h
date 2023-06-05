#ifndef STILL_H
#define STILL_H

#include "Component.h"

class Still : public Component {
    private:
        SDL_Surface * Surface;
    public:
        Still(std::string FileUrl,SDL_Surface * WindowSurface){
            Surface = SDL_LoadBMP(FileUrl.c_str());
            this->WindowSurface = WindowSurface;
        }
        ~Still(){
            SDL_FreeSurface(Surface);
        }
        void Update() override {
            
        }
};

#endif