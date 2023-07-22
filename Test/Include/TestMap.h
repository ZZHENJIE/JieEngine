#pragma once

#include "GameMap.h"
#include "JieEngine.h"
#include "Player.h"
#include <iostream>

using namespace std;
using namespace JieEngine;

void MeshSystem(EntityManage Entity);
void RigidBodySystem(EntityManage Entity);
void TransformSystem(EntityManage Entity);

class TestMap : public GameMap{
    public:
        TestMap(){
            ComponentManage::EnrollComponent<Transform>();
            ComponentManage::EnrollComponent<Mesh>();
            ComponentManage::EnrollComponent<RigidBody>();

            Resource.SManage->EnrollReviseSystem<Transform>(TransformSystem);
            Resource.SManage->EnrollReviseSystem<Mesh>(MeshSystem);
            Resource.SManage->EnrollReviseSystem<RigidBody>(RigidBodySystem);
        }
        virtual void Update() override;
        virtual void Event(SDL_Event Event) override;
};