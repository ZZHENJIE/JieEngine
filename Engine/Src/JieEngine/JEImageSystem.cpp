#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

void JieEngine::JEImageSystem(JEUnInt EntityID){
    auto ImageComponent = JEComponentManage::GetComponentData<JEImage>(EntityID);
    if(Resource.ResourceFile != nullptr){
        auto Surface = Resource.ResourceFile->Image(ImageComponent.Name);
        if(Surface != nullptr){
            auto Transform = JEGetBodyTransform(JEComponentManage::GetComponentData<JEPhysics>(EntityID).Body);
            SDL_Texture * Image = SDL_CreateTextureFromSurface(Resource._Renderer,Surface);
            JERectF Dstrect = {
                (Transform.Pos.X - (ImageComponent.Size.W/2)),
                (Transform.Pos.Y - (ImageComponent.Size.H/2)),
                ImageComponent.Size.W,
                ImageComponent.Size.H
            };
            SDL_RenderCopyExF(Resource._Renderer,Image,NULL,&Dstrect,Transform.Angle * -180 / M_PI,NULL,SDL_FLIP_NONE);
            SDL_DestroyTexture(Image);
            SDL_FreeSurface(Surface);
        }
    }
}