#include "JieEngine/JE.h"
#include "JieEngine/JE_Component.h"

using namespace JieEngine;

JEGlobalResourceComponent JieEngine::Resource;

unordered_map<string,JEComponent> JEComponentManage::ComponentData;

void JieEngine::JEInit(){
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
    TTF_Init();
    Resource.Run = true;
    Resource.FixedFPS = -1;
    Resource.GameMap = nullptr;
    Resource._ChangeMap = nullptr;
    SDL_RenderClear(Resource._Renderer);
}

void JieEngine::JEQuit(){
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(Resource._Renderer);
    delete Resource.Box2DWorld;
}