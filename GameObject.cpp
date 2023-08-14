#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "raylib.h"



GameObject::GameObject(glm::vec2 position)
{
	transform = new ATransform(position);
}

GameObject::GameObject(GameObject& parent, glm::vec2 position)
{
	transform = new ATransform(position, parent.transform);
}




GameObject::~GameObject() {
	
	delete transform;
	for (int i = 0; i < components.size(); i++) {
		components[i] = nullptr;
		delete components[i];
	}
}

void GameObject::AddComponent(Component* component)
{
	components.push_back(component);

}

void GameObject::Update()
{
	for (int i = 0; i < components.size(); i++) {
		components[i]->Update();
	}

}

void GameObject::Draw()
{
	DrawCircle(transform->GetGlobalPosition().x, transform->GetGlobalPosition().y, 10, RED);
	
	for (int i = 0; i < components.size(); i++) {
		components[i]->Draw();
	}

}
