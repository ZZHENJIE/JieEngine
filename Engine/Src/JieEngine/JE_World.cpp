#include "JieEngine/JE_World.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_System.h"

using namespace JieEngine;

JEWorld::JEWorld(JESize2D WorldSize,JEPoint2D Gravity){
    this->_WorldSize = WorldSize;
    this->_DebugDraw = new JEDebugDraw();
    JEVec2 _Gravity(Gravity.X, -1 * Gravity.Y);
    Resource._Box2DWorld = new b2World(_Gravity);
    this->_WorldBorder = JECreateWorldBorder(WorldSize);
    Resource._Box2DWorld->SetDebugDraw(this->_DebugDraw);
}

JEWorld::~JEWorld(){
    delete this->_DebugDraw;
    for(int Iterate = 0; Iterate < 4; Iterate++){
        Resource._Box2DWorld->DestroyBody(_WorldBorder[Iterate]);
    }
    delete [] _WorldBorder;
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
        }
        Resource._Box2DWorld->Step(0.01f, 6, 3);
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
    this->~JEWorld();
}

JELog JEWorld::SetIcon(const char * FileName){
    SDL_Surface * Icon = Resource.ResourceFile->Image(FileName);
    if(Icon != nullptr){
        SDL_SetWindowIcon(this->_Window,Icon);
        SDL_FreeSurface(Icon);
        return SUCCEED;
    }
    return RESOURCE_LOAD_ERROR;
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