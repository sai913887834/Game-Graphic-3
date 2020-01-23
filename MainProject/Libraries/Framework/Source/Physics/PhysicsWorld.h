#pragma once

namespace fw
{
    class PhysicsWorld
    {
    public:
       // PhysicsWorld();
        virtual ~PhysicsWorld();
        virtual void Update(float deltaTime) = 0;

        virtual PhysicsBody* CreateBody(Vector2 pos, float angle, bool isDynamic, void* pUserData) = 0;
    };
}
