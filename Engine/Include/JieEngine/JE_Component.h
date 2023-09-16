#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEEntity;
class JEMap;

class JEComponentManage final{
public:
    template <typename T>
    static void EnrollComponent(void(*DestroyFunction)(JEUnInt EntityID)){
        ComponentData[typeid(T).name()].Data = vector<experimental::any>();
        ComponentData[typeid(T).name()].Destroy = DestroyFunction;
    }

    template <typename T>
    static void CreateComponentData(JEUnInt EntityID,T Data){
        if(EntityID >= ComponentData[typeid(T).name()].Data.size()){
            ComponentData[typeid(T).name()].Data.resize(EntityID + 1);
        }
        ComponentData[typeid(T).name()].Data.at(EntityID) = Data;
    }

    template <typename T>
    static void RemoveComponentData(JEUnInt EntityID){
        (*ComponentData[typeid(T).name()].Destroy)(EntityID);
    }

    template <typename T>
    static T & GetComponentData(JEUnInt EntityID){
        return experimental::any_cast<T&>(ComponentData[typeid(T).name()].Data.at(EntityID));
    }

private:

    friend JEEntity;

    friend JEMap;

    static unordered_map<string,JEComponent> ComponentData;
};

};