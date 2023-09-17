#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

void JEImageSystem(JEUnInt EntityID);

void JEAnimationSystem(JEUnInt EntityID);

class JESystem final{

public:

    JESystem();

    void Update();

    void AddFunction(void(*Function)(JEUnInt EntityID));

    void RemoveFunction(void(*Function)(JEUnInt EntityID));

    template <typename T>
    void AddComponentFunction(void(*Function)(JEUnInt EntityID)){
        this->_ComponentSystem[typeid(T).name()] = Function;
    }

    template <typename T>
    void RemoveComponentFunction(void(*Function)(JEUnInt EntityID)){
        this->_ComponentSystem.erase(this->_ComponentSystem.find(typeid(T).name()));
    }

private:

    vector<void(*)(JEUnInt EntityID)> _FunctionList;

    unordered_map<string,void(*)(JEUnInt EntityID)> _ComponentSystem;

};

}