#include "System.h"
#include <cmath>

using namespace JieEngine;

void JieEngine::RigidBodySystem(std::vector<std::shared_ptr<Entity>> EntityManage){
    for(auto Iterate : ComponentManage::GetEntityIDJVector<RigidBody>()){
        Transform & ObjectTransform = EntityManage[Iterate]->GetComponent<Transform>();
        RigidBody & ObjectRigidBody = EntityManage[Iterate]->GetComponent<RigidBody>();
        if(ObjectRigidBody.IsEnable == true){
            if(ObjectRigidBody.XForce != 0){
                int XForce = (2.0/ObjectRigidBody.Weight) * ObjectRigidBody.XForce;
                ObjectTransform.Pos.x += XForce;
                ObjectRigidBody.XForce /= 3;
            }
            if(ObjectRigidBody.YForce > 0){
                float YForce = (2.0/ObjectRigidBody.Weight) * ObjectRigidBody.YForce;
                ObjectTransform.Pos.y -= YForce;
                ObjectRigidBody.YForce /= 2;
            }else if(ObjectRigidBody.YForce < 0){
                ObjectTransform.Pos.y += ObjectRigidBody.Weight * 0.2;
            }
        }
    }
}