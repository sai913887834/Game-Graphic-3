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
	void PhysicsBody2D::AddBox(Vector3 size, Vector3 offset)
	{

		b2PolygonShape box;
		box.SetAsBox(size.x / 2, size.y / 2);
		b2FixtureDef fixureDef = DefineFixture(box);
		m_pBody->CreateFixture(&fixureDef);


	}
	void PhysicsBody2D::AddCircle(float radius, Vector3 offset)
	{
		


	}
	b2Body* PhysicsBody2D::GetBody()
	{
		return m_pBody;
	}
	b2FixtureDef PhysicsBody2D::DefineFixture(const b2Shape& shape)
	{

		b2FixtureDef def;

		def.shape = &shape;
		def.density = 1;
		def.isSensor = false;
		def.friction = 0.2f;
		def.restitution = 0.0f;
		return def;

	}
}
