#include "Component.h"

Component::Component()
{
	parent = nullptr;
}

Component::~Component()
{
}

void Component::AddParent(GameObject& parent)
{
	this->parent = &parent;
}

