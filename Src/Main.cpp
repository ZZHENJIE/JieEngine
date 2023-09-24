#include "Main.h"

int main(int argc,char * argv[]){

    JEInit();
    
    JEChangeGameMap(new Main());
    
    JEWorld * GameWorld = new JEWorld({640.0f,480.0f},{0.0f,10.0f});

    GameWorld->CreateWindowAndRenderer("JieEngine",640,480);

    GameWorld->Booting();

    JEQuit();

    return 0;
}