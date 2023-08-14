#include "Component.h"

Component::Component(GameObject* parent)
{
	this->parent = parent;
}

Component::~Component()
{
}

void Component::Update()
{
}

void Component::Draw()
{
}
