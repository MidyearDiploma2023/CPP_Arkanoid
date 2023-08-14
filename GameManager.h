#pragma once
#include <vector>
class GameObject;
class GameManager {

private:
	GameManager();
	~GameManager();
	static GameManager* instance;
	std::vector<GameObject*> gameObjects;

	int targetFPS;
	int windowWidth;
	int windowHeight;

	float fixedDelta;
	float deltaTime;
	float currentFixedCount;

public:
	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager* GetInstance();
	
	const float GetDeltaTime() const;
	const float GetFixedDelta() const;

	void Update();
	void Draw();
	void Run();



};
