#pragma once

#include "JUnVector.h"
#include "System.h"
#include "GameMap.h"
#include "Component.h"

namespace JieEngine{

    typedef struct Point2D final{
        int x;
        int y;
    }Point2D;

    typedef struct Size2D final{
        int w;
        int h;
    }Size2D;

    void InitEngine();

    void QuitEngine();

    class Window final{
        public:
            Window(const char * Title,int W,int H,int X,int Y,SDL_WindowFlags Flags);
            void Booting();
        private:
            SDL_Window * _Window;
    };
};