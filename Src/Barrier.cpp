#include "Barrier.h"

Barrier::Barrier(){
    this->AddComponent(new Mesh(this->ID));
}

Barrier::~Barrier(){
    
}

void Barrier::Update(){
            
}
void Barrier::Event(SDL_Event Event){
    
}