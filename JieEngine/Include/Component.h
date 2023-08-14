#pragma once

#include "JUnVector.h"
#include <unordered_map>
#include <experimental/any>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

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
        JUnInt FixedFPS;
        shared_ptr<SystemManage> SManage;
        bool Quit;
        SDL_Renderer * WindowRender;
        JUnVector _GenerateEntityID;
        unordered_map<string,shared_ptr<JUnVector>> _CategoryEntityID;
        shared_ptr<GameMap> _GameMap;
    };

    struct Transform{
        Point2D Pos;
        Size2D Size;
        float Revolve;
    };

    struct Mesh{
        bool IsEnable;
        bool IsDeBug;
        void (*CollideFunction)(Entity * Object_1,Entity * Object_2);
    };

    struct RigidBody{
        bool IsEnable;
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
            static EntityIDJVector GetEntityIDJVector(){
                return EntityIDJVector{
                    Resource._CategoryEntityID[typeid(T).name()]->Begin(),
                    Resource._CategoryEntityID[typeid(T).name()]->Size()
                };
            }
    };

};