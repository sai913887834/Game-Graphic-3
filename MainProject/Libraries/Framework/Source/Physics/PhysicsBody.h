#pragma once

namespace fw
{
	class PhysicsBody
	{


	public:


		virtual Vector3 GetPosition() = 0;
		fw::PhysicsBody* GetPhysicsBody();
		virtual void AddBox(Vector3 size, Vector3 offset) = 0;
		virtual void AddCircle(float radius, Vector3 offset) = 0;
		

	};
}