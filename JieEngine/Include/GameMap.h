#pragma once

#include "System.h"
#include "Entity.h"

namespace JieEngine{
    class Window;
    class Entity;

    class GameMap{
        public:
            virtual void AddEntity(Entity * Player) final;
            virtual void Update() = 0;
            virtual void Event(SDL_Event Event) = 0;
            friend Window;
        private:
            virtual void _MapUpdate() final;
            virtual void _MapEvent(SDL_Event Event) final;
            EntityManage _EntityManage;
    };
};