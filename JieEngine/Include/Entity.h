#pragma once

#include "JUnVector.h"
#include "Component.h"
#include <SDL2/SDL.h>

namespace JieEngine{
    class GameMap;
    
    class Entity{
        public:
            Entity();
            Entity(Entity *& Ptr);
            ~Entity();
            template <typename T>
            void AddComponent(T Parameter){
                this->Components[typeid(T).name()].Data = Parameter;
                this->Components[typeid(T).name()].Index = ComponentManage::CreateComponent<T>(this->ID);
            }
            template <typename... Args>
            void AddComponents(Args... Parameter){
                ((this->AddComponent<Args>(Parameter)), ...);
            }
            template<typename T>
            T & GetComponent(){
                return std::experimental::any_cast<T&>(Components[typeid(T).name()]);
            }
            template<typename... Args>
            void ReviseComponents(Args... Parameter){
                ((this->Components[typeid(Args).name()] = Parameter), ...);
            }
            template<typename T>
            bool IsPossessComponent(){
                for (auto Temp : this->Components) {
                    if (Temp.second.Data.type() == typeid(T)){
                        return true;
                    }
                }
                return false;
            }
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
        private:
            std::unordered_map<std::string,ComponentData> Components;
            int ID;
    };
};