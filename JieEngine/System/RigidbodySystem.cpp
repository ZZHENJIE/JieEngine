#include "../System.h"

void RigidbodySystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Temp : Rigidbody::EntityID){
        Rigidbody & EntityRigidbody = EntityVector[Temp].get()->GetComponent<Rigidbody>();
        if(EntityRigidbody.Enable == true){

            Transform & EntityTransform = EntityVector[Temp].get()->GetComponent<Transform>();

            if(EntityRigidbody.Y > 0){
                EntityTransform.Position.y += EntityRigidbody.Weight * EntityRigidbody.Y;
                EntityRigidbody.Y *= EntityRigidbody.Resistance;
            }

            if(EntityRigidbody.Y < 0){
                EntityTransform.Position.y += EntityRigidbody.Weight * EntityRigidbody.Y;
            }
            
            if(EntityRigidbody.X > 0){
                EntityTransform.Position.x += EntityRigidbody.Weight * EntityRigidbody.X;
                EntityRigidbody.X *= EntityRigidbody.Resistance;
            }

            if(EntityRigidbody.X < 0){
                EntityTransform.Position.x += EntityRigidbody.Weight * EntityRigidbody.X;
                EntityRigidbody.X *= EntityRigidbody.Resistance;
            }

        }
    }
}