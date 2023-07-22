#include "JieEngine.h"

using namespace JieEngine;

void JieEngine::InitEngine(){
    Resource.SManage = make_shared<SystemManage>();
    Resource.Quit = true;
}

void JieEngine::QuitEngine(){

}

Window::Window(const char * Title,int W,int H,int X,int Y,SDL_WindowFlags Flags){
    this->_Window = SDL_CreateWindow(Title,X,Y,W,H,Flags);
}

void Window::Booting(){
    SDL_Event Event;
    while(Resource.Quit){
        if(SDL_PollEvent(&Event)){
            if(Event.type == SDL_QUIT){
                Resource.Quit = false;
            }else{
                Resource._GameMap->_MapEvent(Event);
            }
        }
        Resource._GameMap->_MapUpdate();
    }
}