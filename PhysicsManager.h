#pragma once
#include <vector>
class Rigidbody;
class PhysicsManager {
private:
	std::vector <Rigidbody*> rigidbodies;


private:
	PhysicsManager();
	~PhysicsManager();
	static PhysicsManager* instance;

public:
	PhysicsManager(PhysicsManager& other) = delete;
	void operator=(const PhysicsManager&) = delete;


	void RegisterRigidbody(Rigidbody* body);

	void Update();
	static PhysicsManager* GetInstance();

	void CleanUp();

};