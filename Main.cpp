#include "Game.h"
#include "OneMap.h"

int main(int argc,char * argv[])
{
    Game World("JieEngine",500,500);

    GameMap * Test = new OneMap;

    World.SetGameMap(Test);

    return 0;
}