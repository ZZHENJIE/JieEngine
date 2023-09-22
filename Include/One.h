#pragma once

#include "JieEngine/JE_Map.h"
#include "Player.h"
#include "Barrier.h"
#include "Test.h"

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
        Resource._Box2DWorld->DebugDraw();
        
    }
    void Event(SDL_Event Event){
        if(Event.key.type == SDL_KEYDOWN){
            switch(Event.key.keysym.sym){
                case SDLK_n:{
                    auto _Test = make_shared<Test>();
                    TestID = _Test->GetID();
                    this->AddEntity(_Test);
                    break;
                }
                case SDLK_m:{
                    if(TestID > 1){
                        this->RemoveEntity(TestID);
                        TestID--;
                    }
                    break;
                }
                case SDLK_l:{
                    JEChangeGameMap(new One());
                    break;
                }
            }
        }
    }
    JEUnInt TestID = 0;
};