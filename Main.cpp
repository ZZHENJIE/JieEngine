#include "MWindow.h"
#include "Player.h"

#define WINDOW_W 500
#define WINDOW_H 500

int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    MWindow * Window = new MWindow("JieEngine",WINDOW_W,WINDOW_H);

    Animal * player = new Player("Player.bmp",{50,50},4,5,Window->GetWindowSurface());

    Window->SetAnimalStillNumber(1,0);

    Window->AddAnima(player);

    while(true){
        if(Window->ListenEvent() == SDL_QUIT){
            break;
        }
    }

    SDL_Quit();

    return 0;
}