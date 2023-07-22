#include "Component.h"

Transform::Transform(SDL_Point Position,SDL_Size Size,double Rotation){}

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
    int Count = 0;
    SDL_Log("111");
    // for(auto Temp = this->EntityID.begin();Temp != this->EntityID.end();Temp++){
    //     if(Count == this->VectorID){
    //         this->EntityID.erase(Temp);
    //         break;
    //     }
    //     Count++;
    // }
}

Rigidbody::Rigidbody(int EntityId,signed int X,signed int Y,int Weight,float Resistance,bool Enable){
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

    if(Weight == 0){
        this->Weight = 0;
    }else{
        this->Weight = Weight;
    }

    if(Resistance == 0){
        this->Resistance = 0;
    }else{
        this->Resistance = Resistance;
    }

    if(Enable){
        this->Enable = true;
    }else{
        this->Enable = false;
    }
}

Rigidbody::~Rigidbody(){
    
}