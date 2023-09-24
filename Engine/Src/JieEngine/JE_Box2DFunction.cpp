#include "JieEngine/JE_Box2DFunction.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Entity.h"

using namespace JieEngine;

JETransform JieEngine::JEGetBodyTransform(b2Body * Body){
    JETransform Data;
    Data.Position.X = Body->GetPosition().x;
    Data.Position.Y = -1 * Body->GetPosition().y;
    Data.Angle = Body->GetAngle();
    return Data;
}

void JieEngine::JEBodyApplyLinearImpulse(b2Body * Body,JEPoint2D Force){
    JEVec2 _Force(Force.X,-1 * Force.Y);
    Body->ApplyLinearImpulse(_Force,Body->GetWorldCenter(),true);
}

JEDebugDraw::JEDebugDraw(){
    this->m_drawFlags = e_shapeBit;
}

void JEDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    for(int Iterators = 0; Iterators < vertexCount; Iterators++){
        if(Iterators != vertexCount - 1){
            b2Vec2 Point = vertices[Iterators];
            b2Vec2 NextPoint = vertices[Iterators + 1];
            SDL_RenderDrawLineF(Resource._Renderer,Point.x,-1 * Point.y,NextPoint.x, -1 *NextPoint.y);
        }else{
            b2Vec2 Point = vertices[Iterators];
            b2Vec2 BeginPoint = vertices[0];
            SDL_RenderDrawLineF(Resource._Renderer,Point.x,-1 *Point.y,BeginPoint.x,-1 *BeginPoint.y);
        }
    }
}

void JEDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    for(int Iterators = 0; Iterators < vertexCount; Iterators++){
        if(Iterators != vertexCount - 1){
            b2Vec2 Point = vertices[Iterators];
            b2Vec2 NextPoint = vertices[Iterators + 1];
            SDL_RenderDrawLineF(Resource._Renderer,Point.x,-1 * Point.y,NextPoint.x, -1 *NextPoint.y);
        }else{
            b2Vec2 Point = vertices[Iterators];
            b2Vec2 BeginPoint = vertices[0];
            SDL_RenderDrawLineF(Resource._Renderer,Point.x,-1 *Point.y,BeginPoint.x,-1 *BeginPoint.y);
        }
    }
}

void JEDebugDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    JEPoint2D Position = {center.x,-1 * center.y};
    for (int Iterators = 0; Iterators < 360; Iterators++) {
        float Angle = Iterators * M_PI / 180.0f;
        int X = Position.X + radius * cos(Angle);
        int Y = Position.Y + radius * sin(Angle);
        SDL_RenderDrawPoint(Resource._Renderer, X, Y);
    }
}

void JEDebugDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    JEPoint2D Position = {center.x,-1 * center.y};
    for (int Iterators = 0; Iterators < 360; Iterators++) {
        float Angle = Iterators * M_PI / 180.0f;
        int X = Position.X + radius * cos(Angle);
        int Y = Position.Y + radius * sin(Angle);
        SDL_RenderDrawPoint(Resource._Renderer, X, Y);
    }
}

void JEDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    SDL_RenderDrawLineF(Resource._Renderer,p1.x,-1 * p1.y,p2.x,-1 * p2.y);
}

void JEDebugDraw::DrawTransform(const b2Transform& xf){

}

void JEDebugDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color){
    SDL_SetRenderDrawColor(Resource._Renderer,color.r * 255,color.g * 255,color.b * 255,color.a * 255);
    SDL_RenderDrawPointF(Resource._Renderer,p.x,-1 * p.y);
}

JEPolygonPointVector JieEngine::JECreateJEPolygonPointVector(){
    return make_shared<vector<JEPoint2D>>();
}

b2Body * JieEngine::JECreateRectBody(JESize2D Size,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData){
    b2BodyDef BodyDef;
    BodyDef.type = Type;
    auto Position = JEComponentManage::GetComponentData<JETransform>(Entity->GetID()).Position;
    BodyDef.position.Set(Position.X,-1 * Position.Y);
    b2Body * Data = nullptr;
    if(Entity == nullptr){
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,nullptr);
    }else{
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,(void*)Entity);
    }
    b2PolygonShape RectBox;
    RectBox.SetAsBox(Size.W/2,Size.H/2);
    b2FixtureDef FixtureDef;
    FixtureDef.shape = &RectBox;
    FixtureDef.density = BodyData.Density;
    FixtureDef.friction = BodyData.Friction;
    Data->CreateFixture(&FixtureDef);
    return Data;
}

b2Body * JieEngine::JECreatePolygonBody(JEPolygonPointVector PointData,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData){
    b2Vec2 * Vertices = new b2Vec2[PointData->size()];
    for(int Iterators = 0; Iterators < PointData->size(); Iterators++){
        Vertices[Iterators].Set(PointData->at(Iterators).X,-1 * PointData->at(Iterators).Y);
    }
    b2BodyDef BodyDef;
    BodyDef.type = Type;
    BodyDef.position.Set(0.0f,0.0f);
    b2Body * Data = nullptr;
    if(Entity == nullptr){
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,nullptr);
    }else{
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,(void*)Entity);
    }
    b2PolygonShape PolygonShape;
    PolygonShape.Set(Vertices,PointData->size());
    b2FixtureDef FixtureDef;
    FixtureDef.shape = &PolygonShape;
    FixtureDef.density = BodyData.Density;
    FixtureDef.friction = BodyData.Friction;
    FixtureDef.restitution = BodyData.Restitution;
    Data->CreateFixture(&FixtureDef);
    delete [] Vertices;
    return Data;
}

b2Body * JieEngine::JECreateCircleBody(float Radius,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData){
    b2BodyDef BodyDef;
    BodyDef.type = Type;
    auto Position = JEComponentManage::GetComponentData<JETransform>(Entity->GetID()).Position;
    BodyDef.position.Set(Position.X,-1 * Position.Y);
    b2Body * Data = nullptr;
    if(Entity == nullptr){
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,nullptr);
    }else{
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,(void*)Entity);
    }
    b2CircleShape CircleShape;
    CircleShape.m_radius = Radius;
    b2FixtureDef FixtureDef;
    FixtureDef.shape = &CircleShape;
    FixtureDef.density = BodyData.Density;
    FixtureDef.friction = BodyData.Friction;
    FixtureDef.restitution = BodyData.Restitution;
    Data->CreateFixture(&FixtureDef);
    return Data;
}

b2Body * JieEngine::JECreateLineBody(JEPoint2D PointA,JEPoint2D PointB,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData){
    b2BodyDef BodyDef;
    BodyDef.type = Type;
    BodyDef.position.Set(0.0f,0.0f);
    b2Body * Data = nullptr;
    if(Entity == nullptr){
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,nullptr);
    }else{
        Data = Resource._Box2DWorld->CreateBody(&BodyDef,(void*)Entity);
    }
    b2EdgeShape LineShape;
    JEVec2 Vec2A(PointA.X,-1 * PointA.Y);
    JEVec2 Vec2B(PointB.X,-1 * PointB.Y);
    LineShape.SetTwoSided(Vec2A,Vec2B);
    b2FixtureDef FixtureDef;
    FixtureDef.shape = &LineShape;
    FixtureDef.density = BodyData.Density;
    FixtureDef.friction = BodyData.Friction;
    FixtureDef.restitution = BodyData.Restitution;
    Data->CreateFixture(&FixtureDef);
    return Data;
}

b2Body ** JieEngine::JECreateWorldBorder(JESize2D WorldSize){

    b2Body ** Data = new b2Body*[4];

    Data[0] = JECreateLineBody({
        0,0
    },{
        WorldSize.W,0
    },
    b2_staticBody,nullptr);

    Data[0]->SetTitle("WorldBorder_Top");

    Data[1] = JECreateLineBody({
        WorldSize.W,0
    },{
        WorldSize.W,WorldSize.H
    },
    b2_staticBody,nullptr);

    Data[1]->SetTitle("WorldBorder_Right");

    Data[2] = JECreateLineBody({
        WorldSize.W,WorldSize.H
    },{
        0,WorldSize.H
    },
    b2_staticBody,nullptr);

    Data[2]->SetTitle("WorldBorder_Bottom");

    Data[3] = JECreateLineBody({
        0,WorldSize.H
    },{
        0,0
    },
    b2_staticBody,nullptr);

    Data[3]->SetTitle("WorldBorder_Left");

    return Data;
}