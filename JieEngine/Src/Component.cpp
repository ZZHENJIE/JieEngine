#include "../Component.h"

Transform::Transform(SDL_Point Position,SDL_Size Size,double Rotation):Position(this->Position),Size(this->Size),Rotation(this->Rotation){}


Mesh::Mesh(int EntityId,bool IsVirtual):IsVirtual(this->IsVirtual){
    this->EntityID.push_back(EntityId);
    this->VectorID = this->EntityID.size() - 1;
}

Mesh::~Mesh(){
    
}

Rigidbody::Rigidbody(int EntityId,int X,int Y,int Weight):X(this->X),Y(this->Y),Weight(this->Weight){
    this->EntityID.push_back(EntityId);
    this->VectorID = this->EntityID.size() - 1;
}

Rigidbody::~Rigidbody(){
    
}