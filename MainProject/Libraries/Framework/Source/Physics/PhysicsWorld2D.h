#pragma once

#include "PhysicsWorld.h"
//#include "box2d/b2_world_callbacks.h"

class b2World;

namespace fw
{
    class PhysicsBody2D;
    class Box2DContactListener;
    class PhysicsWorld2D : public PhysicsWorld
    {
    protected:
        b2World* m_pWorld;
        Vector2* m_Position;
        Box2DContactListener* m_pContactListener;

    public:
        PhysicsWorld2D();
        virtual ~PhysicsWorld2D();

        virtual void Update(float deltaTime) override;
        virtual PhysicsBody* CreateBody(Vector2 pos, float angle, bool isDynamic, void* pUserData);

       // m_pContactListener = 


    };

 
}
