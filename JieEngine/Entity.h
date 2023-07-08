#pragma once

#include "Component.h"

struct Entity{
    public:
        Entity();
        ~Entity();
        int ID;
        template<typename T>
        void AddComponent(T component){
            Components[typeid(T).name()] = component;
        }
        template<typename T>
        T& GetComponent(){
            return std::experimental::any_cast<T&>(Components[typeid(T).name()]);
        }
        virtual void Update() = 0;
        virtual void Event(SDL_Event Event) = 0;
    protected:
        std::unordered_map<std::string, std::experimental::any> Components;
};