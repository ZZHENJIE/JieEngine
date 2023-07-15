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
        Mesh(int EntityId,bool Enable = true);
        ~Mesh();
        bool Enable;
        static bool DeBug;
        static std::vector<int> EntityID;
    private:
        int VectorID;
};

class Rigidbody{
    public:
        Rigidbody(int EntityId,signed int X = 0,signed int Y = 0,int Weight = 0,bool Enable = true);
        ~Rigidbody();
        signed int X;
        signed int Y;
        int Weight;
        bool Enable;
        static std::vector<int> EntityID;
    private:
        int VectorID;
};