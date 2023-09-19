#pragma once

#include "JE_Struct.h"
#include "JE_Component.h"

namespace JieEngine{

class JEMap;
class JESystemManage;

using namespace std;

class JEEntity{
public:
    JEEntity();

    ~JEEntity();

    template <typename T>
    void AddComponent(T Data){
        ComponentList.push_back(typeid(T).name());
        JEComponentManage::CreateComponentData<T>(this->ID,Data);
    }

    template <typename T>
    void RemoveComponent(){
        for(int Iterate = 0;Iterate < ComponentList.size();Iterate++){
            if(ComponentList.at(Iterate) == typeid(T).name()){
                ComponentList.erase(ComponentList.begin() + Iterate);
            }
        }
        JEComponentManage::RemoveComponentData<T>(this->ID);
    }

    template <typename T>
    T & GetComponent(){
        return JEComponentManage::GetComponentData<T>(this->ID);
    }

    JEUnInt GetID();

private:

    friend JEMap;

    friend JESystemManage;

    JEUnInt ID;
    static JEContainer<JEUnInt> EntityIDAssignment;
    vector<string> ComponentList;
    virtual void Update() = 0;
    virtual void Event(SDL_Event Event) = 0;
    bool _Lock;
};

};