#include "System.h"

void MeshSystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    int TouchGround [Mesh::EntityID.size()] = {0};
    for(auto Detect1 : Mesh::EntityID){
        Mesh & Detect1Mesh = EntityVector[Detect1].get()->GetComponent<Mesh>();
        bool Detect1IsMoveEntity = false;
        try{
            Rigidbody & EntityRigidbody = EntityVector[Detect1].get()->GetComponent<Rigidbody>();
            Detect1IsMoveEntity = true;
        }catch(const std::exception & E){}
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
                    bool Detect2IsMoveEntity = false;
                    try{
                        Rigidbody & EntityRigidbody = EntityVector[Detect2].get()->GetComponent<Rigidbody>();
                        Detect2IsMoveEntity = true;
                    }catch(const std::exception & E){}
                    SDL_Rect DetectRect = {0,0,0,0};
                    if(SDL_IntersectRect(&Detect1Rect,&Detect2Rect,&DetectRect) == SDL_TRUE){
                        EntityVector[Detect1].get()->Collide(EntityVector[Detect2].get());
                        EntityVector[Detect2].get()->Collide(EntityVector[Detect1].get());
                        if(DetectRect.w == Detect1Rect.w || DetectRect.w == Detect2Rect.w){
                            if(DetectRect.y == Detect2Rect.y){//Detect2上方发生碰撞
                                TouchGround[Detect1] = 1;
                                if(Detect1IsMoveEntity == true && Detect2IsMoveEntity == true){
                                    Detect1Transform.Position.y = DetectRect.h/2 - Detect1Rect.h;
                                    Detect2Transform.Position.y = DetectRect.h/2;
                                }else if(Detect1IsMoveEntity == true){
                                    Detect1Transform.Position.y = Detect2Rect.y - Detect1Rect.h;
                                }else if(Detect2IsMoveEntity == true){
                                    Detect2Transform.Position.y = Detect1Rect.y + Detect1Rect.h;
                                }
                            }else if((DetectRect.y + DetectRect.h) == (Detect2Rect.y + Detect2Rect.h)){//Detect2下方发生碰撞
                                TouchGround[Detect2] = 1;
                                if(Detect1IsMoveEntity == true && Detect2IsMoveEntity == true){
                                    Detect1Transform.Position.y = DetectRect.h/2;
                                    Detect2Transform.Position.y = DetectRect.h/2 - Detect2Rect.h;
                                }else if(Detect1IsMoveEntity == true){
                                    Detect1Transform.Position.y = Detect2Rect.y + Detect2Rect.h;
                                }else if(Detect2IsMoveEntity == true){
                                    Detect2Transform.Position.y = Detect1Rect.y - Detect2Rect.h;
                                }
                            }
                        }
                        if(DetectRect.h == Detect1Rect.h || DetectRect.h == Detect2Rect.h){
                            if(DetectRect.x == Detect2Rect.x){//Detect2左边发生碰撞
                                if(Detect1IsMoveEntity == true && Detect2IsMoveEntity == true){
                                    Detect1Transform.Position.x = DetectRect.w/2 - Detect1Rect.w;
                                    Detect2Transform.Position.x = DetectRect.w/2;
                                }else if(Detect1IsMoveEntity == true){
                                    Detect1Transform.Position.x = Detect2Rect.x - Detect1Rect.w;
                                }else if(Detect2IsMoveEntity == true){
                                    Detect2Transform.Position.x = Detect1Rect.x + Detect1Rect.w;
                                }
                            }else if((DetectRect.x + DetectRect.w) == (Detect2Rect.x + Detect2Rect.w)){//Detect2右边发生碰撞
                                if(Detect1IsMoveEntity == true && Detect2IsMoveEntity == true){
                                    Detect1Transform.Position.x = DetectRect.w/2;
                                    Detect2Transform.Position.x = DetectRect.w/2 - Detect2Rect.w;
                                }else if(Detect1IsMoveEntity == true){
                                    Detect1Transform.Position.x = Detect2Rect.x + Detect2Rect.w;
                                }else if(Detect2IsMoveEntity == true){
                                    Detect2Transform.Position.x = Detect1Rect.x - Detect2Rect.w;
                                }
                            }
                        }
                    }else{
                        if(Detect2Rect.y == Detect1Rect.y + Detect1Rect.h && Detect1Rect.x > Detect2Rect.x - Detect1Rect.w && Detect1Rect.x < Detect2Rect.x + Detect2Rect.w){
                            TouchGround[Detect1] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < Mesh::EntityID.size(); i++){
        try{
            Rigidbody & EntityRigidbody = EntityVector[i].get()->GetComponent<Rigidbody>();
            if(TouchGround[i] == 0){
                EntityRigidbody.Y += 1;
            }else{
                EntityRigidbody.Y = 0;
            }
        }catch(const std::exception & E){}
    }
}