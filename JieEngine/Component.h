#pragma once

#include "JieEngine.h"

class Transform{
    public:
        Transform(int EntityId,SDL_Point Position = {0,0},SDL_Size Size = {0,0},double Rotation = 0);
        ~Transform();
        SDL_Point Position;
        SDL_Size Size;
        double Rotation;
        static std::vector<int> EntityComponent;
};

class Mesh{
    public:
        Mesh(int EntityId,bool IsVirtual = false);
        ~Mesh();
        bool IsVirtual;
        static std::vector<int> EntityComponent;
};

class Rigidbody{
    public:
        Rigidbody(int EntityId,int Up = 0,int Down = 0,int Left = 0,int Right = 0);
        ~Rigidbody();
        int Up;
        int Down;
        int Left;
        int Right;
        static std::vector<int> EntityComponent;
};