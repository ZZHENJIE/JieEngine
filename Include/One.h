#pragma once

#include "JieEngine/JE_Map.h"
#include "Player.h"
#include "Barrier.h"

using namespace JieEngine;

class One : public JEMap{
public:
    One(){
        
    }
    ~One(){

    }
private:
    void Init(){
        this->AddEntity<Player>();
        this->AddEntity<Barrier>();
    }
    void Update(){
        Resource.Box2DWorld->DebugDraw();
        
    }
    void Event(SDL_Event Event){
        
    }
};