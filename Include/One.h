#pragma once

#include "JieEngine/JE_Map.h"
#include "Player.h"
#include "Barrier.h"

using namespace JieEngine;

class One : public JEMap{
public:
    One(){
        this->EntityManage.push_back(make_shared<Player>());
        this->EntityManage.push_back(make_shared<Barrier>());
    }
    ~One(){

    }
private:
    void Update(){
        Resource.Box2DWorld->DebugDraw();
    }
    void Event(SDL_Event Event){
        
    }
};