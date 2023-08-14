#include "Transform.h"

ATransform::ATransform(glm::vec2 position) : ATransform{position, nullptr}
{
}

ATransform::ATransform(glm::vec2 position, ATransform* parent) : localPosition{position}, parent{parent}, isDirty{true}
{
    /*localPosition = position;
    this->parent = parent;
    isDirty = true;*/
    if (parent != nullptr) {
        parent->children.push_back(this);
    }
    UpdateTransform();
}

ATransform::~ATransform()
{
    for (int i = 0; i < children.size(); i++) {
        children[i]->parent = nullptr;
    }
        

}

void ATransform::UpdateTransform()
{
    if (isDirty) {
        if (parent == nullptr) {
            globalPosition = localPosition;
        }
        else {
            globalPosition = parent->globalPosition + localPosition;
        }
        for (int i = 0; i < children.size(); i++) {
            children[i]->isDirty = true;
            children[i]->UpdateTransform();
        }
        isDirty = false;
    }
    else {
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->isDirty) {
                children[i]->UpdateTransform();
            }
        }

    }
    

}

const glm::vec2 ATransform::GetLocalPosition()
{
    if (isDirty) {
        UpdateTransform();
    }
    return localPosition;
}

const glm::vec2 ATransform::GetGlobalPosition()
{
    if (isDirty) {
        UpdateTransform();
    }
    return globalPosition;
}

void ATransform::Translate(const glm::vec2 translation)
{
    localPosition += translation;
    isDirty = true;
}
