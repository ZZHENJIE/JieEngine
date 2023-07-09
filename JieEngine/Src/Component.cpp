#include "../Component.h"

Transform::Transform(int EntityId,SDL_Point Position,SDL_Size Size,double Rotation):Position(this->Position),Size(this->Size),Rotation(this->Rotation){
    this->EntityComponent.push_back(EntityId);
}

Transform::~Transform(){

}

Mesh::Mesh(int EntityId,bool IsVirtual):IsVirtual(this->IsVirtual){
    this->EntityComponent.push_back(EntityId);
}

Mesh::~Mesh(){
    
}

Rigidbody::Rigidbody(int EntityId,int X,int Y,int Weight):X(this->X),Y(this->Y),Weight(this->Weight){
    this->EntityComponent.push_back(EntityId);
}

Rigidbody::~Rigidbody(){
    
}