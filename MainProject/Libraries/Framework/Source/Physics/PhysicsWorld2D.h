#pragma once

#include "PhysicsWorld.h"

class b2World;

namespace fw
{
    class PhysicsBody2D;

    class PhysicsWorld2D : public PhysicsWorld
    {
    protected:
        b2World* m_pWorld;
        Vector2* m_Position;

    public:
        PhysicsWorld2D();
        virtual ~PhysicsWorld2D();

        virtual void Update(float deltaTime) override;
        virtual PhysicsBody* CreateBody(Vector2 pos, float angle, bool isDynamic, void* pUserData);
    };
}
