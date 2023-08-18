#pragma once

#include "GameMap.h"

namespace JieEngine{

    void InitEngine();

    void QuitEngine();

    class Window final{
        public:
            Window(const char * Title,int W,int H,int X,int Y,SDL_WindowFlags Flags);
            ~Window();
            void SetIcon(const char * FileUrl);
            void SetWindowSize(Size2D Size);
            void Booting();
        private:
            SDL_Window * _Window;
    };
};