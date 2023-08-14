#pragma once

#include "GameMap.h"
#include "JieEngine.h"
#include "Player.h"
#include <iostream>

using namespace std;
using namespace JieEngine;

void MeshSystem(EntityVector EntityManage);
void RigidBodySystem(EntityVector EntityManage);

class TestMap : public GameMap{
    public:
        TestMap(){
            ComponentManage::EnrollComponent<Mesh>();
            ComponentManage::EnrollComponent<RigidBody>();

            Resource.SManage->EnrollReviseSystem<Mesh>(MeshSystem);
            Resource.SManage->EnrollReviseSystem<RigidBody>(RigidBodySystem);
        }
        virtual void Update() override;
        virtual void Event(SDL_Event Event) override;
};