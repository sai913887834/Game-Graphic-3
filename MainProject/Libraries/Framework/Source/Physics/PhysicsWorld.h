#pragma once

namespace fw
{
    class PhysicsWorld
    {
    public:
       // PhysicsWorld();
        virtual ~PhysicsWorld();
        virtual void Update(float deltaTime) = 0;
    };
}
