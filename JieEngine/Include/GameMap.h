#pragma once

#include "System.h"

namespace JieEngine{
    class Window;

    class GameMap{
        public:
            template <typename T>
            void AddEntity(Entity * Type){
                this->EntityManage[Type->ID] = make_shared<T>(Type);
            }
            template <typename T>
            void RemoveEntity(Entity * Type){
                EntityCache.push_back(Type->ID);
                
            }
            friend Window;
        private:
            std::vector<std::shared_ptr<Entity>> EntityManage;
            std::vector<int> EntityCache;
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
            virtual void _MapUpdate() final;
            virtual void _MapEvent(SDL_Event Event) final;
    };
};