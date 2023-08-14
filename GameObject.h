#pragma once
#include <vector>
#include "glm/glm/glm.hpp"

class ATransform;
class Component;

class GameObject {
protected:

	std::vector<Component*> components;
	ATransform* transform;

public:
	GameObject(glm::vec2 position);
	GameObject(GameObject& parent, glm::vec2 position);
	~GameObject();

	void AddComponent(Component* component);

	void Update();
	void Draw();


	ATransform& GetTransform();




};