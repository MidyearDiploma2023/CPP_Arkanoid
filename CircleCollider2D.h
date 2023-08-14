#pragma once
#include "Collider.h"
#include "glm/glm/glm.hpp"
class CircleCollider2D : public Collider {
public:
	float radius;
public:
	

	CircleCollider2D(int id, float radius);
	CircleCollider2D(int id, Rigidbody* connectedRigidBody, float radius);

	virtual bool CheckForCollisions(Collider& other) override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void ResolveCollision(CircleCollider2D& other, float penetration, glm::vec2 hitLocation) override;


};