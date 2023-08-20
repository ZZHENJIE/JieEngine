#pragma once

#include "JContainer.h"
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

    using JUnInt = uint32_t;
    using EntityVector = std::vector<std::shared_ptr<Entity>>;

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
    
    struct GlobalResourceComponent final {
        JUnInt FPS;
        JUnInt FixedFPS;
        shared_ptr<SystemManage> SManage;
        bool Run;
        SDL_Renderer * WindowRender;
        JContainer<JUnInt> _GenerateEntityID;
        unordered_map<string,shared_ptr<JContainer<JUnInt>>> _CategoryEntityID;
        shared_ptr<GameMap> _GameMap;
    };

    struct Transform{
        Point2D Pos;
        Size2D Size;
        float Revolve;
    };

    struct Mesh{
        bool IsEnable;
        void (*CollideFunction)(Entity * Object_1,Entity * Object_2);
        static bool IsDeBug;
    };

    struct RigidBody{
        bool IsEnable;
        int XForce;
        int YForce;
        float Weight;
    };

    extern GlobalResourceComponent Resource;
    
    class ComponentManage final {
        public:
            template <typename T>
            static void EnrollComponent(){
                Resource._CategoryEntityID[typeid(T).name()] = make_shared<JContainer<JUnInt>>();
                Resource._CategoryEntityID[typeid(T).name()]->SetNull(-1);
            }
            template <typename T>
            static int CreateComponent(JUnInt EntityID){
                return Resource._CategoryEntityID[typeid(T).name()]->Add(EntityID);
            }
            template <typename T>
            static void DestroyComponent(JUnInt Index){
                Resource._CategoryEntityID[typeid(T).name()]->Remove(Index);
            }
            static void DestroyComponent(ComponentData Data){
                Resource._CategoryEntityID[Data.Data.type().name()]->Remove(Data.Index);
            }
            template <typename T>
            static JContainer<JUnInt> & GetEntityIDJVector(){
                return * Resource._CategoryEntityID[typeid(T).name()];
            }
    };

};