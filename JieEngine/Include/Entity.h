#pragma once

#include "Component.h"

namespace JieEngine{
    class Entity{
        public:
            Entity(const char * Title);
            Entity(Entity * Ptr);
            ~Entity();
            template <typename T>
            void AddComponent(T Parameter){
                this->Components[typeid(T).name()].Data = Parameter;
                if(typeid(T) == typeid(Transform)){
                    this->Components[typeid(T).name()].Index = 0;
                }else{
                    this->Components[typeid(T).name()].Index = ComponentManage::CreateComponent<T>(this->ID);
                }
            }
            template <typename... Args>
            void AddComponents(Args... Parameter){
                ((this->AddComponent<Args>(Parameter)), ...);
            }
            template<typename T>
            T & GetComponent(){
                return std::experimental::any_cast<T&>(Components[typeid(T).name()].Data);
            }
            template<typename... Args>
            void ReviseComponents(Args... Parameter){
                ((this->Components[typeid(Args).name()].Data = Parameter), ...);
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
            const char * Title;
            friend GameMap;
        private:
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
            std::unordered_map<std::string,ComponentData> Components;
            int ID;
    };
};