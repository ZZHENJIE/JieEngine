#include "System.h"

using namespace JieEngine;

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    SDL_Rect CollideRect = {0,0,0,0};
    for(auto IterateTemp = ComponentManage::GetEntityIDJVector<Mesh>().begin();IterateTemp != ComponentManage::GetEntityIDJVector<Mesh>().end() - 1; IterateTemp++){
        int Iterate = *IterateTemp;
        Transform & Object1 = EntityManage[Iterate]->GetComponent<Transform>();
        Transform & Object2 = EntityManage[Iterate + 1]->GetComponent<Transform>();
        SDL_Rect Object1Rect = {
            Object1.Pos.x,
            Object1.Pos.y,
            Object1.Size.w,
            Object1.Size.h
        };
        SDL_Rect Object2Rect = {
            Object2.Pos.x,
            Object2.Pos.y,
            Object2.Size.w,
            Object2.Size.h
        };
        if(Mesh::IsDeBug == true){
            SDL_RenderDrawRect(Resource.WindowRender,&Object1Rect);
            if(IterateTemp == ComponentManage::GetEntityIDJVector<Mesh>().end() - 2){
                SDL_RenderDrawRect(Resource.WindowRender,&Object2Rect);
            }
        }
        if(SDL_IntersectRect(&Object1Rect,&Object2Rect,&CollideRect) == SDL_TRUE){
            if(EntityManage[Iterate]->GetComponent<Mesh>().IsEnable == true){
                if(EntityManage[Iterate + 1]->GetComponent<Mesh>().IsEnable == true){
                    
                }else{
                    
                }
            }
        }else if(EntityManage[Iterate]->IsPossessComponent<RigidBody>() == true){
            EntityManage[Iterate]->GetComponent<RigidBody>().YForce = -1;
        }
    }
}

