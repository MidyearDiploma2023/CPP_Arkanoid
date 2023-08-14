#include "CircleCollider2D.h"
#include "raylib.h"
#include "GameObject.h"
#include "Transform.h"
#include "Rigidbody.h"

CircleCollider2D::CircleCollider2D(int id, float radius) : Collider{ id, nullptr, ColliderType::CIRCLE2D }, radius{radius}
{
}

CircleCollider2D::CircleCollider2D(int id, Rigidbody* connectedRigidBody, float radius) : Collider{ id, connectedRigidBody, ColliderType::CIRCLE2D }, radius{ radius } {
}

bool CircleCollider2D::CheckForCollisions(Collider& other)
{
	for (int i = 0; i < overlaps.size(); i++) {
		if (overlaps[i]->id == other.id) {
			return true;
		}
	}


	if (other.type == ColliderType::CIRCLE2D) {

		auto circle = dynamic_cast<CircleCollider2D&> (other);

		if (CheckCollisionCircles(Vector2{ parent->GetTransform().GetGlobalPosition().x, parent->GetTransform().GetGlobalPosition().y }, radius,
			Vector2{ circle.parent->GetTransform().GetGlobalPosition().x, circle.parent->GetTransform().GetGlobalPosition().y }, circle.radius))
		
		{
			glm::vec2 direction = glm::normalize(parent->GetTransform().GetGlobalPosition() - circle.parent->GetTransform().GetGlobalPosition());
			float distance = glm::distance(parent->GetTransform().GetGlobalPosition(), circle.parent->GetTransform().GetGlobalPosition());
			float radiusCombined = radius + circle.radius;
			float depth = radiusCombined - distance;
			bool contains = false;
			overlaps.push_back(&other);
			ResolveCollision(circle, depth, direction * depth);
			return true;
		}

		return false;
	}
	return false;
}

void CircleCollider2D::Update()
{

}

void CircleCollider2D::Draw()
{
	DrawCircle(parent->GetTransform().GetGlobalPosition().x, parent->GetTransform().GetGlobalPosition().y, 10, GREEN);
}

void CircleCollider2D::ResolveCollision(CircleCollider2D& other, float penetration, glm::vec2 hitLocation)
{
	if (connectedRigidbody && other.connectedRigidbody) {

		glm::vec2 normal = glm::normalize(parent->GetTransform().GetGlobalPosition() -other.parent->GetTransform().GetGlobalPosition());

		parent->GetTransform().Translate(normal * penetration * 0.5f);
		other.parent->GetTransform().Translate(normal * -penetration * 0.5f);

		

		glm::vec2 impulse1 = connectedRigidbody->GetVelocity() + 1.f * normal * (glm::dot(normal, connectedRigidbody->GetVelocity()));
		glm::vec2 impulse2 = other.connectedRigidbody->GetVelocity() + 1.f * normal * (glm::dot(normal, other.connectedRigidbody->GetVelocity()));

		connectedRigidbody->ApplyImpulse(impulse2);
		other.connectedRigidbody->ApplyImpulse(impulse1);
	}


}
