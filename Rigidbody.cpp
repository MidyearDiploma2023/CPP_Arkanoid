#include "Rigidbody.h"
#include "GameObject.h"
#include "Transform.h"
#include "raylib.h"
#include "PhysicsManager.h"
#include "GameManager.h"
#include "Collider.h"
Rigidbody::Rigidbody() : Rigidbody{glm::vec2{0,0}}
{
	collider = nullptr;
}

Rigidbody::Rigidbody(glm::vec2 intialVelocity) : velocity{ intialVelocity }
{
	PhysicsManager::GetInstance()->RegisterRigidbody(this);
	collider = nullptr;
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Update()
{
	parent->GetTransform().Translate(velocity * GameManager::GetInstance()->GetFixedDelta());

}

void Rigidbody::Draw()
{
	

}

void Rigidbody::ApplyImpulse(const glm::vec2 force)
{
	velocity += force;
}

const glm::vec2& Rigidbody::GetVelocity() const
{
	return velocity;
}

void Rigidbody::RegisterCollider(Collider* collider)
{
	this->collider = collider;
}

void Rigidbody::CheckForCollisions(Rigidbody& rb)
{
	if (&rb == this || collider == nullptr) {
		return;
	}
	collider->CheckForCollisions(*rb.collider);


}


