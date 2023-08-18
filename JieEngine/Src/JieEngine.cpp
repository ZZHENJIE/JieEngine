#include "JieEngine.h"

using namespace JieEngine;

void JieEngine::InitEngine(){
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
    TTF_Init();
    Resource.SManage = make_shared<SystemManage>();
    Resource.Run = true;
    Resource.FixedFPS = -1;
    Resource._GenerateEntityID.SetNull(-1);
    SDL_RenderClear(Resource.WindowRender);
}

void JieEngine::QuitEngine(){
    SDL_DestroyRenderer(Resource.WindowRender);
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
}

Window::Window(const char * Title,int W,int H,int X,int Y,SDL_WindowFlags Flags){
    this->_Window = SDL_CreateWindow(Title,X,Y,W,H,Flags);
    Resource.WindowRender = SDL_CreateRenderer(this->_Window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

Window::~Window(){
    SDL_DestroyWindow(this->_Window);
}

void Window::SetIcon(const char * FileUrl){
    SDL_SetWindowIcon(this->_Window,SDL_LoadBMP(FileUrl));
}

void Window::SetWindowSize(Size2D Size){
    SDL_SetWindowSize(this->_Window,Size.w,Size.h);
}

void Window::Booting(){
    SDL_Event Event;
    Uint32 Begin;

    while(Resource.Run){

        Begin = SDL_GetTicks();

        if(SDL_PollEvent(&Event)){
            if(Event.type == SDL_QUIT){
                Resource.Run = false;
            }else{
                Resource._GameMap->_MapEvent(Event);
            }
        }

        Resource._GameMap->_MapUpdate();

        if(Resource.FixedFPS != -1){
            if(SDL_GetTicks() - Begin < (1000/Resource.FixedFPS))
            {
                SDL_Delay((1000/Resource.FixedFPS) - (SDL_GetTicks() - Begin));
            }
        }

        if (SDL_GetTicks() != Begin) {
            Resource.FPS = 1000 / (SDL_GetTicks() - Begin);
        }

    }
}