#include "FrameworkPCH.h"

#include "PhysicsWorld2D.h"
#include "box2d/box2d.h"

namespace fw
{
    PhysicsWorld2D::PhysicsWorld2D()
    {
        m_pWorld = new b2World( b2Vec2( 0, -10 ) );
    }

    PhysicsWorld2D::~PhysicsWorld2D()
    {
        delete m_pWorld;
    }

    void PhysicsWorld2D::Update(float deltaTime)
    {
        float timeStep = 1 / 60.0f;
        int velocityIterations = 8;
        int positionIterations = 3;

        m_pWorld->Step( timeStep, velocityIterations, positionIterations );
    }

    PhysicsBody* PhysicsWorld2D::CreateBody(Vector2 pos, float angle, bool isDynamic, void* pUserData)
    {
        b2BodyDef bodydef;
       bodydef.position = b2Vec2( pos.x, pos.y );
        bodydef.angle = angle;
        bodydef.type = b2_dynamicBody;
        bodydef.userData = this;
    
        //m_pBody = m_pScene->GetPhysicsManager()->GetWorld()->CreateBody( &bodydef );
        return nullptr;
    }
}
