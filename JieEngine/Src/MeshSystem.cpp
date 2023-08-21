#include "System.h"

using namespace JieEngine;

int SizeComparison(SDL_Rect * Object1,SDL_Rect * Object2){
    if((Object1->w * Object1->h) > (Object2->w * Object2->h)){
        return 1;
    }else if((Object1->w * Object1->h) < (Object2->w * Object2->h)){
        return 2;
    }
    return 0;
}

void JieEngine::MeshSystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    //碰撞区域
    SDL_Rect CollideRect = {0,0,0,0};
    //记录每个Entity是否触碰到地面
    bool * IsTouchGround = new bool[ComponentManage::GetEntityIDJVector<Mesh>().Size()];
    //遍历对每个Entity检测
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
        //判断是否开启DeBug模式
        if(Mesh::IsDeBug == true){
            SDL_RenderDrawRect(Resource.WindowRender,&Object1Rect);
            if(IterateTemp == ComponentManage::GetEntityIDJVector<Mesh>().end() - 2){
                SDL_RenderDrawRect(Resource.WindowRender,&Object2Rect);
            }
        }
        //判断两个对象是否发生触碰
        if(SDL_IntersectRect(&Object1Rect,&Object2Rect,&CollideRect) == SDL_TRUE){
            //判断对象是否开启Mesh组件
            if(EntityManage[Iterate]->GetComponent<Mesh>().IsEnable == true){
                if(EntityManage[Iterate + 1]->GetComponent<Mesh>().IsEnable == true){
                    //判断碰撞函数是否为空
                    if(EntityManage[Iterate]->GetComponent<Mesh>().CollideFunction != nullptr){
                        (*EntityManage[Iterate]->GetComponent<Mesh>().CollideFunction)(EntityManage[Iterate].get(),EntityManage[Iterate+1].get());
                    }
                    if(EntityManage[Iterate+1]->GetComponent<Mesh>().CollideFunction != nullptr){
                        (*EntityManage[Iterate]->GetComponent<Mesh>().CollideFunction)(EntityManage[Iterate].get(),EntityManage[Iterate+1].get());
                    }
                    //判断Object是否完全相等于碰撞矩形
                    if(SDL_RectEquals(&Object1Rect,&CollideRect) || SDL_RectEquals(&Object2Rect,&CollideRect) == SDL_TRUE){
                        //判断Object是否为能动的物体
                        if(EntityManage[Iterate]->IsPossessComponent<RigidBody>() == true && EntityManage[Iterate+1]->IsPossessComponent<RigidBody>() == true){
                            switch(SizeComparison(&Object1Rect,&Object2Rect)){
                                case 1:{
                                    Object2.Pos.y = Object1Rect.y - Object2Rect.h;
                                    IsTouchGround[Iterate+1] = true;
                                    IsTouchGround[Iterate] = false;
                                    break;
                                }
                                case 2:{
                                    Object1.Pos.y = Object2Rect.y - Object1Rect.h;
                                    IsTouchGround[Iterate] = true;
                                    IsTouchGround[Iterate+1] = false;
                                    break;
                                }
                            }
                            continue;
                        }else if(EntityManage[Iterate]->IsPossessComponent<RigidBody>() == false && EntityManage[Iterate+1]->IsPossessComponent<RigidBody>() == true){
                            Object2.Pos.y = Object1Rect.y - Object2Rect.h;
                            IsTouchGround[Iterate+1] = true;
                            continue;
                        }else if(EntityManage[Iterate]->IsPossessComponent<RigidBody>() == true && EntityManage[Iterate+1]->IsPossessComponent<RigidBody>() == false){
                            Object1.Pos.y = Object2Rect.y - Object1Rect.h;
                            IsTouchGround[Iterate] = true;
                            continue;
                        }
                    }
                    //判断对象Y坐标是否等于另一个(不能动)对象坐标

                }
            }
        }
        //两个Object都未发生碰撞
        IsTouchGround[Iterate] = false;
        IsTouchGround[Iterate + 1] = false;
    }
    delete [] IsTouchGround;
}

