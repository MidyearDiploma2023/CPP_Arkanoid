#include "Collider.h"
#include "Rigidbody.h"

Collider::Collider(int id, ColliderType type): Collider{id, nullptr, type}
{
	
}

Collider::Collider(int id, Rigidbody* connectedRigidBody, ColliderType type) : id{id} 
{
	this->type = type;
	this->connectedRigidbody = connectedRigidBody;
	this->connectedRigidbody->RegisterCollider(this);
}

Collider::~Collider()
{
}

