#pragma once

#include "JieEngine.h"

class Transform{
    public:
        Transform(SDL_Point Position = {0,0},SDL_Size Size = {0,0},double Rotation = 0);
        SDL_Point Position;
        SDL_Size Size;
        double Rotation;
};

class Mesh{
    public:
        Mesh(int EntityId,bool IsVirtual = false);
        ~Mesh();
        bool IsVirtual;
        static bool DeBug;
        bool Enable = true;
        static std::vector<int> EntityID;
    private:
        int VectorID;
};

class Rigidbody{
    public:
        Rigidbody(int EntityId,int X = 0,int Y = 0,int Weight = 0);
        ~Rigidbody();
        int X;
        int Y;
        int Weight;
        bool Enable = true;
        static std::vector<int> EntityID;
    private:
        int VectorID;
};