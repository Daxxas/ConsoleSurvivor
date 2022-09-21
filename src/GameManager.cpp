#include "GameManager.h"

GameManager::GameManager() {
	inputHandler = new InputHandler();
	Vector2* playerSpawnPosition = new Vector2(10, 10);
	player = new Player(*playerSpawnPosition, 1, 1, 1, 1, inputHandler);
    AddEntity(player);

    AddEntity(new BatEnemy(Vector2(20, 20)));

    for (int i = 0; i < maxBullets; ++i) {
        bullets[i] = new Bullet(Vector2(0, 0), Vector2(0, 0), 1, 1);
    }
}

void GameManager::AddEntity(Entity *entity) {
    entities[validEntityCount] = entity;
    entities[validEntityCount]->isActive = true;
    validEntityCount++;
}

void GameManager::RunGameLoop() {

    for (int i = 0; i < validEntityCount; ++i) {
        if(entities[i]->isActive) {
            entities[i]->Update();
        }
    }

	// manage player direction
	// manage entities movement
	// manage shooting
}

Vector2* GameManager::GetPlayerPosition() {
    Vector2* playerPosition = &player->GetPosition();
	return playerPosition;
}

GameManager::~GameManager() = default;






