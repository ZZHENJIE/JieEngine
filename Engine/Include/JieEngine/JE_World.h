#pragma once

#include "JE_Struct.h"
#include "JE_Map.h"
#include "JE_Box2DFunction.h"

namespace JieEngine{

extern JEGlobalResourceComponent Resource;

class JEWorld final{
    public:
        JEWorld(JESize2D WorldSize,JEVec2 Gravity);
        ~JEWorld();
        void CreateWindowAndRenderer(const char * Title,int W,int H,int X = SDL_WINDOWPOS_CENTERED,int Y = SDL_WINDOWPOS_CENTERED,Uint32 WindowFlag = SDL_WINDOW_SHOWN,Uint32 RendererFlag = SDL_RENDERER_ACCELERATED);
        void Booting();
        void SetIcon(const char * FileName);
        void SetWindowSize(JESize2D Size);
        void AddCollisionFunction(JECollisionFunction Function);
        JESize2D GetWorldSize();
    private:
        JieEngine::JESize2D _WorldSize;
        SDL_Window * _Window;
        JEDebugDraw * _DebugDraw;
        vector<b2Body*> _WorldBorder;
        JEContactListener * _ContactListener;
};

};