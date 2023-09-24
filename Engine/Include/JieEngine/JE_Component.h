#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEEntity;
class JEMap;
class JESystemManage;

class JEComponentManage final{
public:

    static void Init(){
        _ComponentData.clear();
    }

    template <typename T>
    static void EnrollComponent(void(*DestroyFunction)(JEUnInt EntityID)){
        _ComponentData[typeid(T).name()].Data = vector<experimental::any>();
        _ComponentData[typeid(T).name()].Destroy = DestroyFunction;
    }

    template <typename T>
    static void CreateComponentData(JEUnInt EntityID,T Data){
        if(EntityID >= _ComponentData[typeid(T).name()].Data.size()){
            _ComponentData[typeid(T).name()].Data.resize(EntityID + 1);
        }
        _ComponentData[typeid(T).name()].Data.at(EntityID) = Data;
    }

    template <typename T>
    static void RemoveComponentData(JEUnInt EntityID){
        if(_ComponentData[typeid(T).name()].Destroy != nullptr){
            (*_ComponentData[typeid(T).name()].Destroy)(EntityID);
        }
    }

    template <typename T>
    static T & GetComponentData(JEUnInt EntityID){
        return experimental::any_cast<T&>(_ComponentData[typeid(T).name()].Data.at(EntityID));
    }

private:

    friend JEEntity;

    friend JEMap;

    friend JESystemManage;

    static map<string,JEComponent> _ComponentData;
};

};