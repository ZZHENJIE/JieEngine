#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

JELog JieEngine::JECreateAnimationImage(const char * ImageName,JEUnInt Split,JEAnimationImage * Data,SDL_RendererFlip Flip){
    SDL_Surface * Surface = Resource.ResourceFile->Image(ImageName);
    if(Surface != nullptr){
        Data->Texture = SDL_CreateTextureFromSurface(Resource._Renderer,Surface);
        Data->Split = Split;
        Data->Size.W = (float)(Surface->w/Split);
        Data->Size.H = (float)Surface->h;
        Data->Flip = Flip;
        Data->PlaySpeed = 5;
        Data->_Split = 0;
        Data->_PlaySpeed = 1;
        SDL_FreeSurface(Surface);
        return SUCCEED;
    }
    return RESOURCE_LOAD_ERROR;
}

void JieEngine::JEAnimationSystem(JEUnInt EntityID){
    auto * Component = &JEComponentManage::GetComponentData<JEAnimation>(EntityID);
    if(Component->Enabled == true){
        JEAnimationImage & AnimationImage = Component->Image[Component->Status];
        JETransform Transform = JEComponentManage::GetComponentData<JETransform>(EntityID);
        JERect Srcrect = {
            (int)AnimationImage.Size.W * (int)AnimationImage._Split,
            0,
            (int)AnimationImage.Size.W,
            (int)AnimationImage.Size.H
        };
        if(AnimationImage._PlaySpeed % AnimationImage.PlaySpeed == 0){
            if(AnimationImage._Split == (AnimationImage.Split - 1)){
                AnimationImage._Split = 0;
            }else{
                AnimationImage._Split ++;
            }
            AnimationImage._PlaySpeed = 1;
        }else{
            AnimationImage._PlaySpeed ++;
        }
        JERectF Dstrect = {
            Transform.Position.X - AnimationImage.Size.W/2,
            Transform.Position.Y - AnimationImage.Size.H/2,
            AnimationImage.Size.W,
            AnimationImage.Size.H
        };
        SDL_RenderCopyExF(Resource._Renderer,AnimationImage.Texture,&Srcrect,&Dstrect,Transform.Angle * -180 / M_PI,NULL,AnimationImage.Flip);
    }
}