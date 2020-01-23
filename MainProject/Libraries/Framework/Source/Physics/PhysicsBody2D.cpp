#include "FrameworkPCH.h"

#include "PhysicsBody2D.h"
#include "box2d/box2d.h"

namespace fw
{
    PhysicsBody2D::PhysicsBody2D(b2Body* pBody)
    {
        m_pBody = pBody;
        
    }

    PhysicsBody2D::~PhysicsBody2D()
    {
    }
    Vector3 PhysicsBody2D::GetPosition()
    {
        return Vector3(m_pBody->GetPosition().x, m_pBody->GetPosition().y);
    }
    b2Body* PhysicsBody2D::GetBody()
    {
        return m_pBody;
    }
}
