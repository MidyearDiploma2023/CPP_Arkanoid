#pragma once
#include "Component.h"
#include "glm/glm/glm.hpp"
class Collider;
class Rigidbody : public Component {

private:
	glm::vec2 velocity;
	Collider* collider;
	//glm::vec2 acceleration;
	//float mass;
public:
	Rigidbody();
	Rigidbody(glm::vec2 intialVelocity);
	~Rigidbody();

	void Update() override;
	void Draw() override;

	void ApplyImpulse(const glm::vec2 force);

	const glm::vec2& GetVelocity() const;
	
	void RegisterCollider(Collider* collider);

	void CheckForCollisions(Rigidbody& rb);
};