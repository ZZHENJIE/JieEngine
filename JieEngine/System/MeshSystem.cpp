#include "../System.h"

void MeshSystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Detect1 : Mesh::EntityComponent){
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
        for(int Detect2 = Detect1 + 1;Detect2 < Mesh::EntityComponent.size();Detect2++){
            
        }
    }
}