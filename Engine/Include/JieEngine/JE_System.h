#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEEntity;

JELog JECreateImage(const char * ImageName,JEPoint2D Position,JEImage * Data,SDL_RendererFlip Flip = SDL_FLIP_NONE);

JELog JECreateAnimationImage(const char * ImageName,JEUnInt Split,JEAnimationImage * Data,SDL_RendererFlip Flip = SDL_FLIP_NONE);

void JEImageSystem(JEUnInt EntityID);

void JEAnimationSystem(JEUnInt EntityID);

class JESystemManage final{

public:

    static void Init();

    static void Update(vector<shared_ptr<JEEntity>> EntityManage);

    static void AddFunction(void(*Function)(JEUnInt EntityID));

    static void RemoveFunction(void(*Function)(JEUnInt EntityID));

    template <typename T>
    static void AddComponentFunction(void(*Function)(JEUnInt EntityID)){
        _ComponentSystem[typeid(T).name()] = Function;
    }

    template <typename T>
    static void RemoveComponentFunction(void(*Function)(JEUnInt EntityID)){
        _ComponentSystem.erase(_ComponentSystem.find(typeid(T).name()));
    }

private:

    static vector<void(*)(JEUnInt EntityID)> _FunctionList;

    static unordered_map<string,void(*)(JEUnInt EntityID)> _ComponentSystem;
};

}