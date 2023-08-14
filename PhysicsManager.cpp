#include "PhysicsManager.h"
#include "Rigidbody.h"
#include <iostream>

PhysicsManager* PhysicsManager::instance = nullptr;


PhysicsManager::PhysicsManager() {

}

PhysicsManager::~PhysicsManager()
{
	std::cout << "Called";
}

PhysicsManager* PhysicsManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new PhysicsManager();
	}
	return instance;
}

void PhysicsManager::CleanUp()
{
	delete instance;
}

void PhysicsManager::RegisterRigidbody(Rigidbody* body)
{
	rigidbodies.push_back(body);
}

void PhysicsManager::Update()
{
	for (int i = 0; i < rigidbodies.size(); i++) {
		
		for (int y = 0; y < rigidbodies.size(); y++) {
			rigidbodies[y]->CheckForCollisions(*rigidbodies[i]);
		}
		rigidbodies[i]->Update();
	}

}
