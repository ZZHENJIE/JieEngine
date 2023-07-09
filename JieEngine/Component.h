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
        static bool DeBug;
        static std::vector<int> EntityComponent;
};

class Rigidbody{
    public:
        Rigidbody(int EntityId,int X = 0,int Y = 0,int Weight = 0);
        ~Rigidbody();
        int X;
        int Y;
        int Weight;
        static std::vector<int> EntityComponent;
};