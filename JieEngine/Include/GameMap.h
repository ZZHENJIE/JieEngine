#pragma once

#include "System.h"

namespace JieEngine{
    class Window;
    class Entity;

    class GameMap{
        public:
            template <typename T>
            void AddEntity(T * Type){
                this->EntityManage.push_back(make_shared<T>(Type));
            }
            friend Window;
        protected:
            std::vector<std::shared_ptr<Entity>> EntityManage;
        private:
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
            virtual void _MapUpdate() final;
            virtual void _MapEvent(SDL_Event Event) final;
    };
};