#pragma once

class GameObject;
class Component {

protected:
	
	GameObject* parent;

public:
	
	Component();
	~Component();

	void AddParent(GameObject& parent);

public:
	virtual void Update() = 0;

	virtual void Draw() = 0;
};
