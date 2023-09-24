#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEEntity;

extern JEContainer<JEUnInt> MixerChannel;

JELog JECreateImage(const char * ImageName,JEImage & Data,SDL_RendererFlip Flip = SDL_FLIP_NONE);

JELog JECreateAnimationImage(const char * ImageName,JEUnInt Split,JEAnimationImage & Data,SDL_RendererFlip Flip = SDL_FLIP_NONE);

JELog JECreateAudio(const char * SoundName,JEAudio & Data,JEUnInt Volume = 50);

void JEDestroyAudio(JEAudio & Data);

void JEImageSystem(JEUnInt EntityID);

void JEAnimationSystem(JEUnInt EntityID);

void JEPhysicsSystem(JEUnInt EntityID);

class JESystemManage final{

public:

    static void Init();

    static void Update(vector<shared_ptr<JEEntity>> EntityManage);

    static void AddFunction(void(*Function)());

    static void RemoveFunction(void(*Function)());

    template <typename T>
    static void AddComponentFunction(void(*Function)(JEUnInt EntityID)){
        _ComponentSystemList[typeid(T).name()] = Function;
    }

    template <typename T>
    static void RemoveComponentFunction(void(*Function)(JEUnInt EntityID)){
        _ComponentSystemList.erase(_ComponentSystemList.find(typeid(T).name()));
    }

private:

    static vector<void(*)()> _FunctionList;

    static map<string,void(*)(JEUnInt EntityID)> _ComponentSystemList;
};

}