#pragma once

#include "JE_Struct.h"
#include "JE_Component.h"

namespace JieEngine{

class JEMap;

using namespace std;

class JEEntity{
public:
    JEEntity();

    ~JEEntity();

    template <typename T>
    void AddComponent(T Data){
        JEComponentManage::CreateComponentData<T>(this->ID,Data);
    }

    template <typename T>
    void RemoveComponent(){
        JEComponentManage::RemoveComponentData<T>(this->ID);
    }

    template <typename T>
    T & GetComponent(){
        return JEComponentManage::GetComponentData<T>(this->ID);
    }

    JEUnInt GetID();

    friend JEMap;
private:
    JEUnInt ID;
    static JEContainer<JEUnInt> EntityIDAssignment;
    virtual void Update() = 0;
    virtual void Event(SDL_Event Event) = 0;
};

};