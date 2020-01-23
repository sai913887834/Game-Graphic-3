#pragma once

namespace fw
{
    class PhysicsBody
    {

        
    public:


         virtual Vector3 GetPosition() = 0;
         fw::PhysicsBody* GetPhysicsBody();

    };
}
