#pragma once

#include "JieEngine/JE_Map.h"
#include "Player.h"
#include "Barrier.h"

using namespace JieEngine;

class Two : public JEMap{
public:
    Two(){
        
    }
    ~Two(){

    }
private:
    void Init(){
        this->AddEntity<Barrier>();
    }
    void Update(){
        Resource._Box2DWorld->DebugDraw();
        
    }
    void Event(SDL_Event Event){

    }
};