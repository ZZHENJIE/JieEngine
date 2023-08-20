#include "TestMap.h"

using namespace JieEngine;

int main(int argc,char * argv[]){

    InitEngine();

    JieEngine::Window Game("JieEngine",500,500,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SDL_WINDOW_SHOWN);

    Resource.FixedFPS = 75;

    Resource._GameMap = make_shared<TestMap>();

    Game.Booting();

    return 0;
}