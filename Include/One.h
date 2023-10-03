#pragma once

#include "JieEngine/JE_Map.h"
#include "Player.h"

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
    }
    void Update(){
        Resource._Box2DWorld->DebugDraw();
        
    }
    void Event(SDL_Event Event){
        
    }
};