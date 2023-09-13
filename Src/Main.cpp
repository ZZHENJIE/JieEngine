#include "JieEngine/JE_World.h"
#include "JieEngine/JE.h"
#include "One.h"

using namespace JieEngine;

int main(int argc,char * argv[]){
    
    JEInit();

    JEVec2 Gravity(0.0f,-10.0f);

    JEWorld * GameWorld = new JEWorld({640.0f,480.0f},Gravity);

    GameWorld->CreateWindowAndRenderer("JieEngine",640,480);

    JEComponentManage::EnrollComponent<JEPhysics>([](JEUnInt EntityID){
        Resource.Box2DWorld->DestroyBody(JEComponentManage::GetComponentData<JEPhysics>(EntityID).Body);
    });

    Resource.GameMap = new One();

    GameWorld->Booting();

    delete GameWorld;

    JEQuit();

    return 0;
}