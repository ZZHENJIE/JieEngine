#include "../Component.h"

Transform::Transform(SDL_Point Position,SDL_Size Size,double Rotation){

}


Mesh::Mesh(int EntityId,bool Enable){
    this->EntityID.push_back(EntityId);
    this->VectorID = this->EntityID.size() - 1;

    if(Enable){
        this->Enable = true;
    }else{
        this->Enable = false;
    }
}

Mesh::~Mesh(){
    
}

Rigidbody::Rigidbody(int EntityId,signed int X,signed int Y,int Weight,bool Enable){
    this->EntityID.push_back(EntityId);
    this->VectorID = this->EntityID.size() - 1;

    if(X == 0){
        this->X = 0;
    }else{
        this->X = X;
    }

    if(Y == 0){
        this->Y = 0;
    }else{
        this->Y = Y;
    }

    if(Y == Weight){
        this->Weight = 0;
    }else{
        this->Weight = Weight;
    }

    if(Enable){
        this->Enable = true;
    }else{
        this->Enable = false;
    }
}

Rigidbody::~Rigidbody(){
    
}