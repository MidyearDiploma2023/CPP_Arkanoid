#include "GameManager.h"
#include "GameObject.h"
#include "raylib.h"
#include <iostream>
#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "CircleCollider2D.h"

GameManager* GameManager::instance = nullptr;


GameManager::GameManager() {
	windowWidth = 450;
	windowHeight = 450;
	targetFPS = 165;
	fixedDelta = 1.f / targetFPS;
	currentFixedCount = 0.f;
	deltaTime = 0.f;
	InitWindow(windowWidth, windowHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	GameObject* gameObject = new GameObject(glm::vec2{ windowWidth / 2 + 100, windowHeight / 2 });
	Rigidbody* rb = new Rigidbody(glm::vec2{ -100, 0 });
	Collider* col = new CircleCollider2D(1, rb, 10);
	gameObject->AddComponent(rb);
	gameObject->AddComponent(col);

	gameObjects.push_back(gameObject);

	GameObject* gameObject2 = new GameObject(glm::vec2{ windowWidth / 2 - 100, windowHeight / 2 });
	Rigidbody* rb2 = new Rigidbody(glm::vec2{ 100, 0 });
	Collider* col2 = new CircleCollider2D(2, rb2, 10);
	gameObject2->AddComponent(rb2);
	gameObject2->AddComponent(col2);

	gameObjects.push_back(gameObject2);
	

}

GameManager::~GameManager()
{

	std::cout << "Called";
	for (int i = 0; i < gameObjects.size(); i++) {
		delete gameObjects[i];
	}
}


GameManager* GameManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new GameManager();
	}
	return instance;
}

const float GameManager::GetDeltaTime() const
{
	return deltaTime;
}

const float GameManager::GetFixedDelta() const
{
	return fixedDelta;
}

void GameManager::Update()
{
	currentFixedCount += deltaTime;
	if (currentFixedCount > fixedDelta) {
		PhysicsManager::GetInstance()->Update();
		currentFixedCount -= fixedDelta;
	}


	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
	}
}

void GameManager::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);
	
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Draw();
	}
	EndDrawing();
	
	
}

void GameManager::Run() {

	while (!WindowShouldClose()) {
		
		Update();
		Draw();
		deltaTime = GetFrameTime();
	}

	PhysicsManager::GetInstance()->CleanUp();
	delete instance;
}
