#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

namespace JieEngine{

    class Entity;
    
    using EntityManage = std::vector<std::shared_ptr<Entity>>;
    using SystemFunction = void (*)(EntityManage);

    class SystemManage final{
        public:
            template <typename T>
            void EnrollReviseSystem(SystemFunction Function){
                this->_SystemFunction[typeid(T).name()] = Function;
            }
            template <typename T>
            void RemoveSystem(){
                this->_SystemFunction.erase(this->_SystemFunction.find(typeid(T).name()));
            }
            void Update(EntityManage EntityVector);
        private:
            unordered_map<string,SystemFunction> _SystemFunction;
    };
};