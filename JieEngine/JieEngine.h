#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <experimental/any>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#define ENTITY_MAX 2048

typedef struct SDL_Size{
    int w;
    int h;
}SDL_Size;

namespace JieEngine{
    void Init();
    void Quit();
    void SetRect(SDL_Rect * Rect,int x,int y, int w,int h);
    void LogRect(SDL_Rect * Rect);
    extern SDL_Renderer * WindowRenderer;
    extern int EntityCountId;
};