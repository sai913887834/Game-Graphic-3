#pragma once

#include "PhysicsBody.h"
class b2Body;
namespace fw
{
    class PhysicsBody2D : public PhysicsBody
    {
    protected:
        b2Body* m_pBody;
    public:
        PhysicsBody2D(b2Body* pBody);
        virtual ~PhysicsBody2D();
       
        virtual Vector3 GetPosition();
        b2Body* GetBody();
        
    };
}
