#include "OneMapStruct.h"

OneMapStruct::OneMapStruct(SDL_Surface * WindowSurface){
    srand((unsigned)time(NULL)); 
    this->WindowSurface = WindowSurface;
    this->PlayerObject = new Player(".\\Resource\\Player.bmp",4,6,{50,50},WindowSurface);
    this->StillCount = 4;
    this->MapStillArray = new Barrier[StillCount];
    for(short i = 0; i < StillCount; i++){
        MapStillArray[i].SetData(".\\Resource\\Barrier.bmp",{WINDOW_W + i * 160,rand() % (WINDOW_H - 200)},WindowSurface);
    }
}

void OneMapStruct::Update(){
    for(short i = 0; i < StillCount; i++){
        MapStillArray[i].Update();
        PlayerObject->Detect(&MapStillArray[i]);
    }
    PlayerObject->Update();
}

void OneMapStruct::WindowEvent(SDL_Event Event){
    switch(Event.key.keysym.sym){
        case SDLK_SPACE:{
            PlayerObject->Jump();
            break;
        }
        case SDLK_a:{
            PlayerObject->MoveLeft();
            break;
        }
        case SDLK_d:{
            PlayerObject->MoveRight();
            break;
        }
    }
}