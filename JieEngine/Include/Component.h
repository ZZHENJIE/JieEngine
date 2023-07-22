#pragma once

#include "JUnVector.h"
#include <unordered_map>
#include <experimental/any>
#include <string>
#include <typeinfo>
#include <memory>
#include <iostream>

using namespace std;

namespace JieEngine{
    class SystemManage;
    class GameMap;

    struct ComponentData{
        std::experimental::any Data;
        int Index;
    };

    struct EntityIDJUnVector final{
        JUnInt * Begin;
        JUnInt Size;
    };
    
    struct GlobalResourceComponent final {
        JUnInt FPS;
        shared_ptr<SystemManage> SManage;
        bool Quit;
        JUnVector _GenerateEntityID;
        unordered_map<string,shared_ptr<JUnVector>> _CategoryEntityID;
        shared_ptr<GameMap> _GameMap;
    };

    extern GlobalResourceComponent Resource;
    
    class ComponentManage final {
        public:
            template <typename T>
            static void EnrollComponent(){
                Resource._CategoryEntityID[typeid(T).name()] = make_shared<JUnVector>();
            }
            template <typename T>
            static int CreateComponent(JUnInt EntityID){
                return Resource._CategoryEntityID[typeid(T).name()]->Push(EntityID);
            }
            template <typename T>
            static void DestroyComponent(JUnInt VectorIndex){
                Resource._CategoryEntityID[typeid(T).name()]->Remove(VectorIndex);
            }
            static void DestroyComponentS(ComponentData Data){
                Resource._CategoryEntityID[Data.Data.type().name()]->Remove(Data.Index);
            }
            template <typename T>
            static EntityIDJUnVector GetEntityIDJUnVector(){
                return EntityIDJUnVector{
                    Resource._CategoryEntityID[typeid(T).name()]->Begin(),
                    Resource._CategoryEntityID[typeid(T).name()]->Size()
                };
            }
    };

    struct Component{
        bool IsEnable;
        bool UIClog;
    };

    struct Mesh : Component{

    };

    struct RigidBody : Component{

    };

    struct Transform : Component{

    };

};