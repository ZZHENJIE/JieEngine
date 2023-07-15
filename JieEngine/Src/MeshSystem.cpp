#include "System.h"

void MeshSystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Detect1 : Mesh::EntityID){
        Mesh & Detect1Mesh = EntityVector[Detect1].get()->GetComponent<Mesh>();
        if(Detect1Mesh.Enable == true){
            Transform & Detect1Transform = EntityVector[Detect1].get()->GetComponent<Transform>();
            SDL_Rect Detect1Rect = {
                Detect1Transform.Position.x,
                Detect1Transform.Position.y,
                Detect1Transform.Size.w,
                Detect1Transform.Size.h
            };
            if(Mesh::DeBug == true){
                SDL_RenderDrawRect(JieEngine::WindowRenderer,&Detect1Rect);
            }
            bool TouchGround = false;
            for(int Detect2 = Detect1 + 1;Detect2 < Mesh::EntityID.size();Detect2++){
                Mesh & Detect2Mesh = EntityVector[Detect2].get()->GetComponent<Mesh>();
                if(Detect2Mesh.Enable == true){
                    Transform & Detect2Transform = EntityVector[Detect2].get()->GetComponent<Transform>();
                    SDL_Rect Detect2Rect = {
                        Detect2Transform.Position.x,
                        Detect2Transform.Position.y,
                        Detect2Transform.Size.w,
                        Detect2Transform.Size.h
                    };
                    SDL_Rect DetectRect = {0,0,0,0};
                    if(SDL_IntersectRect(&Detect1Rect,&Detect2Rect,&DetectRect) == SDL_TRUE){
                        if(DetectRect.x < Detect1Rect.x + Detect1Rect.w/2 && DetectRect.y < Detect1Rect.y + Detect1Rect.h/2){
                            //左上角
                            if(DetectRect.w > DetectRect.h){
                                Detect1Transform.Position.y = Detect2Transform.Position.y - Detect1Transform.Size.h;
                            }else if(DetectRect.w < DetectRect.h){
                                Detect1Transform.Position.x = Detect2Transform.Position.x - Detect1Transform.Size.w;
                            }else{
                                Detect1Transform.Position.y = Detect2Transform.Position.y - Detect1Transform.Size.h;
                                Detect1Transform.Position.x = Detect2Transform.Position.x - Detect1Transform.Size.w;
                            }
                        }
                        if(DetectRect.x > Detect1Rect.x + Detect1Rect.w/2 && DetectRect.y < Detect1Rect.y + Detect1Rect.h/2){
                            //右上角
                            if(DetectRect.w > DetectRect.h){
                                Detect1Transform.Position.y = Detect2Transform.Position.y - Detect1Transform.Size.h;
                            }else if(DetectRect.w < DetectRect.h){
                                Detect1Transform.Position.x = Detect2Transform.Position.x + Detect2Transform.Size.w;
                            }else{
                                Detect1Transform.Position.y = Detect2Transform.Position.y - Detect1Transform.Size.h;
                                Detect1Transform.Position.x = Detect2Transform.Position.x + Detect2Transform.Size.w;
                            }
                        }
                        if(DetectRect.x < Detect1Rect.x + Detect1Rect.w/2 && DetectRect.y > Detect1Rect.y + Detect1Rect.h/2){
                            //左下角
                            if(DetectRect.w > DetectRect.h){
                                Detect1Transform.Position.y = Detect2Transform.Position.y + Detect2Transform.Size.h;
                            }else if(DetectRect.w < DetectRect.h){
                                Detect1Transform.Position.x = Detect2Transform.Position.x - Detect1Transform.Size.w;
                            }else{
                                Detect1Transform.Position.y = Detect2Transform.Position.y + Detect2Transform.Size.h;
                                Detect1Transform.Position.x = Detect2Transform.Position.x - Detect1Transform.Size.w;
                            }
                        }
                        if(DetectRect.x > Detect1Rect.x + Detect1Rect.w/2 && DetectRect.y > Detect1Rect.y + Detect1Rect.h/2){
                            //右下角
                            if(DetectRect.w > DetectRect.h){
                                Detect1Transform.Position.y = Detect2Transform.Position.y + Detect2Transform.Size.h;
                            }else if(DetectRect.w < DetectRect.h){
                                Detect1Transform.Position.x = Detect2Transform.Position.x + Detect2Transform.Size.w;
                            }else{
                                Detect1Transform.Position.y = Detect2Transform.Position.y + Detect2Transform.Size.h;
                                Detect1Transform.Position.x = Detect2Transform.Position.x + Detect2Transform.Size.w;
                            }
                        }
                        if(DetectRect.y > Detect1Rect.y + Detect1Rect.h/2 && DetectRect.w == Detect1Transform.Size.w){
                            TouchGround = true;
                        }
                    }else{
                        if(Detect1Transform.Position.y + Detect1Transform.Size.h == Detect2Transform.Position.y && Detect1Transform.Position.x > Detect2Transform.Position.x - Detect1Transform.Size.w && Detect1Transform.Position.x < Detect2Transform.Position.x + Detect2Transform.Size.w){
                            TouchGround = true;
                        }
                    }
                }
            }
            try{
                Rigidbody & EntityRigidbody = EntityVector[Detect1].get()->GetComponent<Rigidbody>();
                if(TouchGround == false){
                    EntityRigidbody.Y += 1;
                }else{
                    EntityRigidbody.Y = 0;
                }
            }catch(const std::exception & E){}
        }
    }
}