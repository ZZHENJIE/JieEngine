#include "../JieEngine.h"
#include "../Component.h"

int JieEngine::EntityCountId = 0;
SDL_Size JieEngine::WindowSize;
SDL_Renderer * JieEngine::WindowRenderer;

std::vector<int> Mesh::EntityID;
std::vector<int> Rigidbody::EntityID;

bool Mesh::DeBug = false;

void JieEngine::Init(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
    TTF_Init();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    SDL_RenderClear(JieEngine::WindowRenderer);
}

void JieEngine::Quit(){
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(JieEngine::WindowRenderer);
}

void JieEngine::SetRect(SDL_Rect * Rect,int x,int y, int w,int h){
    Rect->x = x;
    Rect->y = y;
    Rect->w = w;
    Rect->h = h;
}

void JieEngine::LogRect(SDL_Rect * Rect){
    SDL_Log("JieEngine: X:%d Y:%d W:%d H:%d \n",Rect->x,Rect->y,Rect->w,Rect->h);
}