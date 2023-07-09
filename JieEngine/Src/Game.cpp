#include "../Game.h"

Game::Game(const char * GameName,int Window_W,int Window_H){
    JieEngine::Init();
    this->Window = SDL_CreateWindow(GameName,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Window_W,Window_H,SDL_WINDOW_SHOWN);
    JieEngine::WindowRenderer = SDL_CreateRenderer(this->Window,-1,0);
    JieEngine::WindowSize = {Window_W,Window_H};
}

Game::Game(const char * GameName,int Window_W,int Window_H,int Position_X,int Position_Y){
    JieEngine::Init();
    this->Window = SDL_CreateWindow(GameName,Position_X,Position_Y,Window_W,Window_H,SDL_WINDOW_SHOWN);
    JieEngine::WindowRenderer = SDL_CreateRenderer(this->Window,-1,0);
    JieEngine::WindowSize = {Window_W,Window_H};
}

Game::~Game(){
    SDL_DestroyWindow(this->Window);
}

void Game::SetWindowIcon(const char * SourceUrl){
    // SDL_SetWindowIcon();
}

void Game::SetWindowSize(int Window_W,int Window_H){
    SDL_SetWindowSize(this->Window,Window_W,Window_H);
    JieEngine::WindowSize = {Window_W,Window_H};
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

        SDL_RenderPresent(JieEngine::WindowRenderer);

        this->FPS_Temp = SDL_GetTicks();
    }
}