#pragma once

#include "JieEngine.h"

class Transform{
    public:
        Transform(int EntityId,SDL_Point Position = {0,0},SDL_Size Size = {0,0},double Rotation = 0);
        SDL_Point Position;
        SDL_Size Size;
        double Rotation;
        static std::vector<int> EntityComponent;
};

class Mesh{
    public:
        Mesh(int EntityId,bool IsVirtual = false);
        bool IsVirtual;
        static std::vector<int> EntityComponent;
};

class Rigidbody{
    
};