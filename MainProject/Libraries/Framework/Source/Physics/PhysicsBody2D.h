#pragma once

#include "PhysicsBody.h"
class b2Body;
struct b2FixtureDef;
class b2Shape;
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

		virtual void AddBox(Vector3 size, Vector3 offset) override;
		virtual void AddCircle(float radius, Vector3 offset) override;
		b2Body* GetBody();


	private:
		b2FixtureDef DefineFixture(const b2Shape& shape);
	};
}
