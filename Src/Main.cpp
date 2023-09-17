#include "JieEngine/JE.h"
#include "One.h"

using namespace JieEngine;

int main(int argc,char * argv[]){
    
    JEVec2 Gravity(0.0f,-10.0f);

    JEWorld * GameWorld = new JEWorld({640.0f,480.0f},Gravity);

    JEInit(GameWorld);

    GameWorld->CreateWindowAndRenderer("JieEngine",640,480);

    JEChangeGameMap(new One());

    GameWorld->Booting();

    delete GameWorld;

    JEQuit();

    return 0;
}