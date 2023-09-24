#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEEntity;

using JEPolygonPointVector = shared_ptr<vector<JEPoint2D>>;

using JECollisionFunction = void (*)(b2Body * ObjectA,b2Body * ObjectB);

JETransform JEGetBodyTransform(b2Body * Body);

void JEBodyApplyLinearImpulse(b2Body * Body,JEPoint2D Force);

class JEDebugDraw : public b2Draw{
public:
    JEDebugDraw();

    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
    void DrawCircle(const b2Vec2& center, float radius, const b2Color& color);

    void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color);

    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

    void DrawTransform(const b2Transform& xf);

    void DrawPoint(const b2Vec2& p, float size, const b2Color& color);
};

JEPolygonPointVector JECreateJEPolygonPointVector();

b2Body * JECreateRectBody(JESize2D Size,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData = {0.0f,0.0f,0.0f});

b2Body * JECreatePolygonBody(JEPolygonPointVector PointData,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData = {0.0f,0.0f,0.0f});

b2Body * JECreateCircleBody(float Radius,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData = {0.0f,0.0f,0.0f});

b2Body * JECreateLineBody(JEPoint2D PointA,JEPoint2D PointB,b2BodyType Type,JEEntity * Entity,JEBodyParameter BodyData = {0.0f,0.0f,0.0f});

b2Body ** JECreateWorldBorder(JESize2D WorldSize);

};