#pragma once

#include "PhysicsWorld.h"


class b2World;

namespace fw
{
    class PhysicsBody2D;
    class Box2DDebugDraw;
    class PhysicsWorld2D : public PhysicsWorld
    {
    protected:
        b2World* m_pWorld;
        Vector2* m_Position;
        Box2DDebugDraw* m_pDebugDraw;

        fw::ShaderProgram* m_pShader;

    public:
        PhysicsWorld2D();
        virtual ~PhysicsWorld2D();

        virtual void Update(float deltaTime) override;
        virtual PhysicsBody* CreateBody(Vector3 pos, float angle, bool isDynamic, void* pUserData);
        void DrawDebugMessage();

    };
}
