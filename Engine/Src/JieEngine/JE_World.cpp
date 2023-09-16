#include "JieEngine/JE_World.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_System.h"

using namespace JieEngine;

JEWorld::JEWorld(JESize2D WorldSize,JEVec2 Gravity){
    this->_WorldSize = WorldSize;
    this->System = new JESystem();
    this->_DebugDraw = new JEDebugDraw();
    Resource.Box2DWorld = new b2World(Gravity);
    this->_WorldBorder = JECreateWorldBorder(WorldSize);
    Resource.Box2DWorld->SetDebugDraw(this->_DebugDraw);
}

JEWorld::~JEWorld(){
    delete this->_DebugDraw;
    delete this->System;
    SDL_DestroyWindow(this->_Window);
}

void JEWorld::CreateWindowAndRenderer(const char * Title,int W,int H,int X,int Y,Uint32 WindowFlag,Uint32 RendererFlag){
    this->_Window = SDL_CreateWindow(Title,X,Y,W,H,WindowFlag);
    Resource._Renderer = SDL_CreateRenderer(this->_Window,-1,RendererFlag);
}

void JEWorld::Booting(){
    SDL_Event WindowEvent;
    JEUnInt Begin;
    while(Resource.Run){
        Begin = SDL_GetTicks();
        if(Resource.GameMap != Resource._ChangeMap){
            delete Resource.GameMap;
            Resource.GameMap = Resource._ChangeMap;
            Resource.GameMap->Init();
        }
        if(SDL_PollEvent(&WindowEvent)){
            if(WindowEvent.type == SDL_QUIT){
                Resource.Run = false;
            }else{
                if(Resource.GameMap != nullptr){
                    Resource.GameMap->_MapEvent(WindowEvent);
                }
            }
        }
        if(Resource.GameMap != nullptr){
            Resource.GameMap->_MapUpdate();
            this->System->Update();
        }
        Resource.Box2DWorld->Step(0.01f, 6, 3);
        SDL_RenderPresent(Resource._Renderer);
        if(Resource.FixedFPS != -1){
            if(SDL_GetTicks() - Begin < (1000/Resource.FixedFPS))
            {
                SDL_Delay((1000/Resource.FixedFPS) - (SDL_GetTicks() - Begin));
            }
        }
        if (SDL_GetTicks() != Begin) {
            Resource.FPS = 1000 / (SDL_GetTicks() - Begin);
        }
    }
}

void JEWorld::SetIcon(const char * FileName){
    if(Resource.ResourceFile != nullptr){
        SDL_SetWindowIcon(this->_Window,Resource.ResourceFile->Image(FileName));
    }
}

void JEWorld::SetWindowSize(JESize2D Size){
    SDL_SetWindowSize(this->_Window,Size.W,Size.H);
}

JESize2D JEWorld::GetWorldSize(){
    return _WorldSize;
}

void JieEngine::JEChangeGameMap(JEMap * GameMap){
    Resource._ChangeMap = GameMap;
}