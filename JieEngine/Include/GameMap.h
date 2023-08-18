#pragma once

#include "System.h"

namespace JieEngine{
    class Window;

    class GameMap{
        public:
            template <typename T>
            void AddEntity(Entity * Type){
                this->EntityManage.insert(this->EntityManage.begin() + Type->ID,make_shared<T>(Type));
            }
            void RemoveEntity(Entity * Type);
            void RemoveEntity(int EntityID);
            std::shared_ptr<Entity> GetEntity(const char * Title);
            std::shared_ptr<Entity> GetEntity(string Title);
            std::shared_ptr<Entity> GetEntity(int EntityID);
            friend Window;
        private:
            std::vector<std::shared_ptr<Entity>> EntityManage;
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
            virtual void _MapUpdate() final;
            virtual void _MapEvent(SDL_Event Event) final;
    };
};