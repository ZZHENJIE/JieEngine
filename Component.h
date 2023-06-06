#ifndef COMPONENT_H
#define COMPONENT_H

#include "JieEngineTest.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Component
{
    protected:
        SDL_Point Position;
        SDL_Point Size;
        SDL_Point * AnimationImagePosition;
        SDL_Surface * WindowSurface;
        SDL_Surface * ImageSurface;
        short ImageInciseNumber = 0;
        short PlaySpeed = 0;
        short AnimationCount = 0;
        short AnimationPlaySpeedCount = 0;
    public:
        SDL_Point * GetPos(){
            return &Position;
        }
        void InciseImage(){
            Size.x = ImageSurface->w/ImageInciseNumber;
            Size.y = ImageSurface->h;
            AnimationImagePosition = new SDL_Point [ImageInciseNumber];
            for(short i = 0; i < ImageInciseNumber; i++){
                AnimationImagePosition[i].x = i * Size.x;
                AnimationImagePosition[i].y = 0;
            }
        }
        void UpdateAnimation(){
            SDL_Rect TempImageSurfacePosition = {AnimationImagePosition[AnimationCount].x,AnimationImagePosition[AnimationCount].y,Size.x,Size.y};
            SDL_Rect TempWindowSurfacePosition = {Position.x,Position.y,Size.x,Size.y};
            SDL_FillRect(WindowSurface,&TempWindowSurfacePosition,0xff);
            SDL_BlitSurface(ImageSurface,&TempImageSurfacePosition,WindowSurface,&TempWindowSurfacePosition);
            if(AnimationPlaySpeedCount % PlaySpeed == 0){
                if(AnimationCount == ImageInciseNumber - 1){
                    AnimationCount = 0;
                }else{
                    AnimationCount++;
                }
                AnimationPlaySpeedCount = 0;
            }
            AnimationPlaySpeedCount ++;
        }
        virtual const char * GetClass(){
            return "Component";
        }
        virtual void Update(){
            this->UpdateAnimation();
        };
};

#endif