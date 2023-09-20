#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

void JieEngine::JEPhysicsSystem(JEUnInt EntityID){
    JETransform * Transform = &JEComponentManage::GetComponentData<JETransform>(EntityID);
    auto Body = JEComponentManage::GetComponentData<JEPhysics>(EntityID).Body;
    auto Temp = JEGetBodyTransform(Body);
    Transform->Position.X = Temp.Position.X;
    Transform->Position.Y = Temp.Position.Y;
    Transform->Angle = Temp.Angle;
}