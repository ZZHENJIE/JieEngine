#pragma once

<<<<<<< HEAD
=======
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Component.h"
>>>>>>> 535fbdba87fd472195cd413d29e283c4d4fc2b79
#include "Entity.h"

using namespace std;

namespace JieEngine{

    class Entity;

    void MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage);
    void RigidBodySystem(std::vector<std::shared_ptr<Entity>> EntityManage);

    class SystemManage final{
        public:
            SystemManage(){
                this->EnrollReviseSystem<Mesh>(MeshSystem);
                this->EnrollReviseSystem<RigidBody>(RigidBodySystem);
            }
            template <typename T>
            void EnrollReviseSystem(void (*Function)(std::vector<std::shared_ptr<Entity>>)){
                this->_SystemFunction[typeid(T).name()] = Function;
            }
            template <typename T>
            void RemoveSystem(){
                this->_SystemFunction.erase(this->_SystemFunction.find(typeid(T).name()));
            }
            void Update(std::vector<std::shared_ptr<Entity>> EntityVector);
        private:
            unordered_map<string,void (*)(std::vector<std::shared_ptr<Entity>>)> _SystemFunction;
    };
};