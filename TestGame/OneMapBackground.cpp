#include "OneMapBackground.h"

OneMapBackground::OneMapBackground(const char * ImageUrl,SDL_Surface * WindowSurface){
    this->BackgroundImage = SDL_LoadBMP(ImageUrl);
    this->WindowSurface = WindowSurface;
}

void OneMapBackground::Update(){
    SDL_BlitSurface(BackgroundImage,NULL,WindowSurface,NULL);
}

void OneMapBackground::WindowEvent(SDL_Event Event){
    
}