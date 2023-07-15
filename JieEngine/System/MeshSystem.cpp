#include "../System.h"

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
            for(int Detect2 = Detect1 + 1;Detect2 < Mesh::EntityID.size();Detect2++){
                Mesh & Detect2Mesh = EntityVector[Detect2].get()->GetComponent<Mesh>();
                if(Detect2Mesh.Enable == true){

                }
            }
        }
    }
}