#pragma once
#include "Component.h"
#include "glm/glm/glm.hpp"
#include <vector>
class CircleCollider2D;
class Rigidbody;
class Collider : public Component {

public: 
	enum ColliderType {CIRCLE2D, BOX2D};
	ColliderType type;
protected:
	Rigidbody* connectedRigidbody;
	std::vector<Collider*> overlaps;

public:
	int id;
	
	
	Collider(int id, ColliderType type);
	Collider(int id, Rigidbody* connectedRigidbody, ColliderType type);
	~Collider();

	virtual bool CheckForCollisions(Collider& other) = 0;
	virtual void ResolveCollision(CircleCollider2D& other, float penetration, glm::vec2 hitLocation) = 0;
};