#pragma once

#include "JieEngine.h"
#include "Entity.h"
#include "Component.h"
#include "System.h"

class GameMap{
    public:
        GameMap();
        ~GameMap();
        virtual void ChangeGameMap(GameMap *& Present,GameMap * Future) final;
        virtual void MapUpdate() final;
        virtual void MapWindowEvent(SDL_Event Event,GameMap *& Present) final;
        virtual void SetCameraBindEntity(Entity * BindEntity) final;
        virtual void WindowEvent(SDL_Event Event,GameMap *& Present) = 0;
        virtual void Update() = 0;
    protected:
        std::vector<std::shared_ptr<Entity>> EntityVector;
        SDL_Point * CameraPosition;
};