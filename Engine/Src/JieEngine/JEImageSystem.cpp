#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

JELog JieEngine::JECreateImage(const char * ImageName,JEPoint2D Position,JEImage * Data,SDL_RendererFlip Flip){
    SDL_Surface * Surface = Resource.ResourceFile->Image(ImageName);
    if(Surface != nullptr){
        Data->Texture = SDL_CreateTextureFromSurface(Resource._Renderer,Surface);
        Data->Transform.Position.X = Position.X;
        Data->Transform.Position.Y = Position.Y;
        Data->Size.W = (float)Surface->w;
        Data->Size.H = (float)Surface->h;
        Data->Transform.Angle = 0.0f;
        Data->Enabled = true;
        Data->Flip = Flip;
        SDL_FreeSurface(Surface);
        return SUCCEED;
    }
    return RESOURCE_LOAD_ERROR;
}

void JieEngine::JEImageSystem(JEUnInt EntityID){
    auto Component = JEComponentManage::GetComponentData<JEImage>(EntityID);
    if(Component.Enabled == true){
        JERectF Dstrect = {
            Component.Transform.Position.X - (Component.Size.W/2),
            Component.Transform.Position.Y - (Component.Size.H/2),
            Component.Size.W,
            Component.Size.H
        };
        SDL_RenderCopyExF(Resource._Renderer,Component.Texture,nullptr,&Dstrect,Component.Transform.Angle * -180 / M_PI,nullptr,Component.Flip);
    }
}