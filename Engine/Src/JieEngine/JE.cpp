#include "JieEngine/JE.h"
#include "JieEngine/JE_Component.h"

using namespace JieEngine;

JEGlobalResourceComponent JieEngine::Resource;

unordered_map<string,JEComponent> JEComponentManage::_ComponentData;

void InitComponentAndSystem(){

    JESystemManage::Init();
    JEComponentManage::Init();

    JEComponentManage::EnrollComponent<JEPhysics>([](JEUnInt EntityID){
        Resource.Box2DWorld->DestroyBody(JEComponentManage::GetComponentData<JEPhysics>(EntityID).Body);
    });

    JEComponentManage::EnrollComponent<JEImage>([](JEUnInt EntityID){
        auto Image = JEComponentManage::GetComponentData<JEImage>(EntityID);
        SDL_DestroyTexture(Image.Texture);
    });

    JEComponentManage::EnrollComponent<JEAnimation>([](JEUnInt EntityID){
        auto Animation = JEComponentManage::GetComponentData<JEAnimation>(EntityID);
        for(auto Iterate : Animation.Image){
            SDL_DestroyTexture(Iterate.second.Texture);
        }
    });

    JESystemManage::AddComponentFunction<JEPhysics>(nullptr);
    JESystemManage::AddComponentFunction<JEImage>(JEImageSystem);
    JESystemManage::AddComponentFunction<JEAnimation>(JEAnimationSystem);
}

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
    InitComponentAndSystem();
}

void JieEngine::JEQuit(){
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(Resource._Renderer);
    delete Resource.Box2DWorld;
}