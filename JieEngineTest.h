#ifndef JIEENGINETEST_H
#define JIEENGINETEST_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class JieEngineTest{
    public:
        static void PrintRectInfo(SDL_Rect * Rect){
            cout << "X:" << Rect->x << " Y:" << Rect->y << " W:" << Rect->w << " H:" << Rect->h << endl;
        }
};

#endif