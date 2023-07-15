#include "../System.h"

void RigidbodySystem(std::vector<std::shared_ptr<Entity>> EntityVector){
    for(auto Temp : Rigidbody::EntityID){
        Rigidbody & EntityRigidbody = EntityVector[Temp].get()->GetComponent<Rigidbody>();
        if(EntityRigidbody.Enable == true){

            Transform & EntityTransform = EntityVector[Temp].get()->GetComponent<Transform>();

            if(EntityRigidbody.Y > 0){
                EntityTransform.Position.y -= EntityRigidbody.Y;
                EntityRigidbody.Y /= 2;
            }

            if(EntityRigidbody.Y < 0){
                EntityTransform.Position.y += EntityRigidbody.Weight;
            }
            
            if(EntityRigidbody.X > 0){
                EntityTransform.Position.x += EntityRigidbody.X;
                EntityRigidbody.X /= 2;
            }

            if(EntityRigidbody.X < 0){
                EntityTransform.Position.x += EntityRigidbody.X;
                EntityRigidbody.X /= 2;
            }

        }
    }
}