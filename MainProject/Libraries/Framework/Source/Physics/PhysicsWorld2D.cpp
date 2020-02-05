#include "FrameworkPCH.h"

#include "PhysicsWorld2D.h"
#include "box2d/box2d.h"
#include"Box2DDebugDraw.h"

namespace fw
{
    
    PhysicsWorld2D::PhysicsWorld2D()
    {

        m_pWorld = new b2World( b2Vec2( 0, -10 ) );
        m_pShader = new ShaderProgram("Data/Shaders/Box2DDebug.vert", "Data/Shaders/Box2DDebug.frag");
       // ShaderProgram* pShaderProgram, MyMatrix* pMatView, MyMatrix* pMatProj
        m_pDebugDraw = new Box2DDebugDraw(m_pShader, nullptr , nullptr);
        m_pWorld->SetDebugDraw(m_pDebugDraw);
       
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

	

    PhysicsBody* PhysicsWorld2D::CreateBody(Vector3 pos, float angle, bool isDynamic, void* pUserData)
    {
		b2BodyDef bodydef;
		bodydef.position = b2Vec2(pos.x, pos.y);
		bodydef.angle = angle;
		bodydef.type = b2_dynamicBody;
		bodydef.userData = this;

		//m_pBody = m_pScene->GetPhysicsManager()->GetWorld()->CreateBody( &bodydef );

		b2Body* pBody = m_pWorld->CreateBody(&bodydef);

		PhysicsBody2D* pPhysicsBody = new PhysicsBody2D(pBody);

		return pPhysicsBody;
    }
    void PhysicsWorld2D::DrawDebugMessage()
    {
    }
}
