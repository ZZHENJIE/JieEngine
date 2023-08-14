#pragma once

#include "JUnVector.h"
#include <unordered_map>
#include <experimental/any>
#include <string>
#include <typeinfo>
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

namespace JieEngine{
    class SystemManage;
    class GameMap;
    class Entity;

    typedef struct Point2D final{
        int x;
        int y;
    }Point2D;

    typedef struct Size2D final{
        int w;
        int h;
    }Size2D;

    struct ComponentData{
        std::experimental::any Data;
        int Index;
    };

    struct EntityIDJVector final{
        JUnInt * Begin;
        JUnInt Size;
    };
    
    struct GlobalResourceComponent final {
        JUnInt FPS;
        shared_ptr<SystemManage> SManage;
        bool Quit;
        SDL_Renderer * WindowRender;
        JUnVector _GenerateEntityID;
        unordered_map<string,shared_ptr<JUnVector>> _CategoryEntityID;
        shared_ptr<GameMap> _GameMap;
    };

    extern GlobalResourceComponent Resource;
    
    class ComponentManage final {
        public:
            ComponentManage();
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
            static EntityIDJVector GetEntityIDJVector(){
                return EntityIDJVector{
                    Resource._CategoryEntityID[typeid(T).name()]->Begin(),
                    Resource._CategoryEntityID[typeid(T).name()]->Size()
                };
            }
    };

    struct Component{
        bool IsEnable;
        bool UIClog;
    };

    struct Transform{
        Point2D Pos;
        Size2D Size;
        float Revolve;
    };

    struct Mesh{
        bool IsEnable;
        void (*Collide)(Entity * Object_1,Entity * Object_2);
    };

    struct RigidBody : Component{

    };

};