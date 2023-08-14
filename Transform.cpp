#include "Transform.h"

ATransform::ATransform(glm::vec2 position) : ATransform{position, nullptr}
{
}

ATransform::ATransform(glm::vec2 position, ATransform* parent) : localPosition{position}, parent{parent}, isDirty{true}
{
    /*localPosition = position;
    this->parent = parent;
    isDirty = true;*/
    
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
    

}

const glm::vec2 ATransform::GetLocalPosition() const
{
    return localPosition;
}

const glm::vec2 ATransform::GetGlobalPosition() const
{
    return globalPosition;
}

void ATransform::Translate(const glm::vec2 translation)
{
    localPosition += translation;
}
