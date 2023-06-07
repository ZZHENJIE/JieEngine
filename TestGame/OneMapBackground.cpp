#include "OneMapBackground.h"

OneMapBackground::OneMapBackground(SDL_Surface * WindowSurface){
    this->BackgroundImage = SDL_LoadBMP(".\\Resource\\Background.bmp");
    this->BackgroundImage1 = SDL_LoadBMP(".\\Resource\\Background1.bmp");
    SetRectInfo(&BackgroundImage1Position,0,0,WINDOW_W,WINDOW_H);
    SetRectInfo(&BackgroundImage1PositionTemp,WINDOW_W,0,WINDOW_W,WINDOW_H);
    this->WindowSurface = WindowSurface;
}

void OneMapBackground::Update(){
    SDL_BlitSurface(BackgroundImage,NULL,WindowSurface,NULL);
    SDL_BlitSurface(BackgroundImage1,&BackgroundImage1Position,WindowSurface,NULL);
    if(BackgroundImage1Position.x >= BackgroundImage1->w - WINDOW_W){
        SDL_BlitSurface(BackgroundImage1,NULL,WindowSurface,&BackgroundImage1PositionTemp);
        BackgroundImage1PositionTemp.x --;
    }
    BackgroundImage1Position.x ++;
    if(BackgroundImage1Position.x == BackgroundImage1->w){
        BackgroundImage1Position.x = 0;
        BackgroundImage1PositionTemp.x = WINDOW_W;
    }
}

void OneMapBackground::WindowEvent(SDL_Event Event){
    
}