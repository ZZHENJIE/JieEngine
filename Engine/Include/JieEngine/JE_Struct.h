#pragma once

#include <unordered_map>
#include <map>
#include <experimental/any>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <string.h>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Box2D/box2d.h"
#include "JE_Container.h"

namespace JieEngine{

using namespace std;

class JEMap;
class JEUnpackData;

using JEUnInt = uint32_t;

enum JELog{
    SUCCEED,
    RESOURCE_LOAD_ERROR,
};

struct JEComponent final{
    vector<experimental::any> Data;
    void(*Destroy)(JEUnInt EntityID);
};

struct JEPoint2D final{
    float X;
    float Y;
};

struct JESize2D final{
    float W;
    float H;
};

struct JEUI {
    JEPoint2D Position;
    JESize2D Size;
    bool Enabled;
};

struct JETitle : JEUI{
    string Text;
};

struct JEButton : JEUI{
    void (*Click)();
    string Text;
};

struct JEUIImage : JEUI{
    SDL_Texture * Texture;
    SDL_RendererFlip Flip;
    float Angle;
};

class JEInterface final{
public:
    JEInterface(JEPoint2D Position,JESize2D Size);
    template<typename T>
    JEInterface * AddControl(T Data){

        return this;
    }
    template<typename T>
    JEInterface * RemoveControl(T Data){
        
        return this;
    }
    void Exec();
private:
    map<string,vector<experimental::any>> UIData;
    SDL_Event Event;
    JEPoint2D Position;
    JESize2D Size;
};

struct JETransform final{
    JEPoint2D Position;
    float Angle;
};

struct JEAudio final{
    Mix_Chunk * Sound;
    JEUnInt Channel;
    JEUnInt Volume;
};

struct JEAnimationImage final{
    SDL_Texture * Texture;
    JESize2D Size;
    JEUnInt Split;
    JEUnInt PlaySpeed;
    SDL_RendererFlip Flip;
    JEUnInt _Split;
    JEUnInt _PlaySpeed;
};

struct JEAnimation final{
    map<string,JEAnimationImage> Image;
    string Status;
    bool Enabled;
};

struct JEImage final{
    SDL_Texture * Texture;
    JESize2D Size;
    SDL_RendererFlip Flip;
    bool Enabled;
};

struct JEPhysics final{
    b2Body * Body;
};

struct JEBodyParameter final{
    float Density;
    float Friction;
    float Restitution;
};

struct JEFileData final{
    char * Data;
    int Size;
};

struct JEGlobalResourceComponent final {
    JEUnInt FPS;
    JEUnInt FixedFPS;
    bool Run;
    JEMap * GameMap;
    JEUnpackData * ResourceFile;
    b2World * _Box2DWorld;
    SDL_Renderer * _Renderer;
    JEMap * _ChangeMap;
};

using JERect = SDL_Rect;

using JERectF = SDL_FRect;

using JEVec2 = b2Vec2;

using JEColor = SDL_Color;

extern JEGlobalResourceComponent Resource;

};