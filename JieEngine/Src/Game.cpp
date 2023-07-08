#include "../Game.h"

Game::Game(const char * GameName,int Window_W,int Window_H){
    JieEngine::Init();
    this->Window = SDL_CreateWindow(GameName,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Window_W,Window_H,SDL_WINDOW_SHOWN);
    JieEngine::WindowRenderer = SDL_CreateRenderer(this->Window,-1,SDL_RENDERER_SOFTWARE);
}

Game::Game(const char * GameName,int Window_W,int Window_H,int Position_X,int Position_Y){
    JieEngine::Init();
    this->Window = SDL_CreateWindow(GameName,Position_X,Position_Y,Window_W,Window_H,SDL_WINDOW_SHOWN);
    JieEngine::WindowRenderer = SDL_CreateRenderer(this->Window,-1,SDL_RENDERER_SOFTWARE);
}

Game::~Game(){
    SDL_DestroyWindow(this->Window);
}

void Game::SetWindowIcon(const char * SourceUrl){
    // SDL_SetWindowIcon();
}

SDL_Size Game::GetWindowSize(){
    SDL_Size Temp = {0,0};
    SDL_GetWindowSize(this->Window,&Temp.w,&Temp.h);
    return Temp;
}

void Game::SetWindowSize(int Window_W,int Window_H){
    SDL_SetWindowSize(this->Window,Window_W,Window_H);
}

void Game::SetGameMap(GameMap * Map){
    SDL_Event Event;
    while (true){
        if(SDL_GetTicks() - this->FPS_Temp < (1000/this->FPS)){
            SDL_Delay((1000/this->FPS) - SDL_GetTicks() + this->FPS_Temp);
        }

        if(SDL_PollEvent(&Event)){
            if(Event.type == SDL_QUIT){
                JieEngine::Quit();
                return;
            }else{
                Map->MapWindowEvent(Event,Map);
            }
        }

        Map->MapUpdate();

        this->FPS_Temp = SDL_GetTicks();
    }
}