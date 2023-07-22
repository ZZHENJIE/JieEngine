#pragma once

#include "JieEngine.h"
#include "GameMap.h"

class Game final{
    public:
        Game(const char * GameName,int Window_W,int Window_H);
        Game(const char * GameName,int Window_W,int Window_H,int Position_X,int Position_Y);
        ~Game();
        void SetWindowIcon(const char * SourceUrl);
        void SetWindowSize(int Window_W,int Window_H);
        void SetGameMap(GameMap * Map);
    private:
        SDL_Window * Window;
        Uint32 FPS = 60;
        Uint32 Ticks_Count = 0;
};