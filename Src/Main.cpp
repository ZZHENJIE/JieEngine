#include "JieEngine/JE.h"
#include "One.h"

using namespace JieEngine;

int main(int argc,char * argv[]){

    JEInit();

    Resource.ResourceFile = new JEUnpackData("./Test.JieEngine");

    JEChangeGameMap(new One());
    
    JEWorld * GameWorld = new JEWorld({640.0f,480.0f},{0.0f,10.0f});

    GameWorld->CreateWindowAndRenderer("JieEngine",640,480);

    GameWorld->Booting();

    JEQuit();

    return 0;
}