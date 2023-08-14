#pragma once
#include "glm/glm/glm.hpp"
#include <vector>

	class GameObject;
	class ATransform {

	private:

		//GameObject* attachedGameObject;
		ATransform* parent;
		std::vector<ATransform*> children;

		glm::vec2 localPosition;
		glm::vec2 globalPosition;
		bool isDirty;

	public:
		ATransform(glm::vec2 position);
		ATransform(glm::vec2 position, ATransform* parent);
		~ATransform();

		void UpdateTransform();

		const glm::vec2 GetLocalPosition();
		const glm::vec2 GetGlobalPosition();

		void Translate(const glm::vec2 translation);
	};
