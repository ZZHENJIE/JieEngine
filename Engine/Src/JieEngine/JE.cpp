#include "JieEngine/JE.h"
#include "JieEngine/JE_Component.h"

using namespace JieEngine;

JEGlobalResourceComponent JieEngine::Resource;

map<string,JEComponent> JEComponentManage::_ComponentData;

void InitComponentAndSystem(){
    
    JESystemManage::Init();
    JEComponentManage::Init();

    JEComponentManage::EnrollComponent<JEPhysics>([](JEUnInt EntityID){
        Resource._Box2DWorld->DestroyBody(JEComponentManage::GetComponentData<JEPhysics>(EntityID).Body);
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

    JEComponentManage::EnrollComponent<JEAudio>([](JEUnInt EntityID){
        auto Audio = JEComponentManage::GetComponentData<JEAudio>(EntityID);
        for(auto Iterate : Audio.Sound){
            Mix_FreeChunk(Iterate.second);
        }
        MixerChannel.Remove(Audio.Channel);
    });

    JEComponentManage::EnrollComponent<JETransform>(nullptr);

    JESystemManage::AddComponentFunction<JEPhysics>(JEPhysicsSystem);
    JESystemManage::AddComponentFunction<JEImage>(JEImageSystem);
    JESystemManage::AddComponentFunction<JEAnimation>(JEAnimationSystem);
    JESystemManage::AddComponentFunction<JETransform>(nullptr);
}

void JieEngine::JEInit(){
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
    TTF_Init();
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
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
    delete Resource.GameMap;
    delete Resource._ChangeMap;
    delete Resource._Box2DWorld;
}