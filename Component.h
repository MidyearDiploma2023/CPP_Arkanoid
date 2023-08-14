#pragma once

class GameObject;
class Component {

private:
	GameObject* parent;
public:
	Component(GameObject* parent);
	~Component();


public:
	void Update();

	void Draw();
};
