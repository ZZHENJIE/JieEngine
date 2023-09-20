#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

JELog JieEngine::JECreateImage(const char * ImageName,JEImage * Data,SDL_RendererFlip Flip){
    SDL_Surface * Surface = Resource.ResourceFile->Image(ImageName);
    if(Surface != nullptr){
        Data->Texture = SDL_CreateTextureFromSurface(Resource._Renderer,Surface);
        Data->Size.W = (float)Surface->w;
        Data->Size.H = (float)Surface->h;
        Data->Enabled = true;
        Data->Flip = Flip;
        SDL_FreeSurface(Surface);
        return SUCCEED;
    }
    return RESOURCE_LOAD_ERROR;
}

void JieEngine::JEImageSystem(JEUnInt EntityID){
    auto Component = JEComponentManage::GetComponentData<JEImage>(EntityID);
    auto Transform = JEComponentManage::GetComponentData<JETransform>(EntityID);
    if(Component.Enabled == true){
        JERectF Dstrect = {
            Transform.Position.X - (Component.Size.W/2),
            Transform.Position.Y - (Component.Size.H/2),
            Component.Size.W,
            Component.Size.H
        };
        SDL_RenderCopyExF(Resource._Renderer,Component.Texture,nullptr,&Dstrect,Transform.Angle * -180 / M_PI,nullptr,Component.Flip);
    }
}