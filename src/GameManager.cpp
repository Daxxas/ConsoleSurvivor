#include "GameManager.h"

GameManager::GameManager() {
	inputHandler = new InputHandler();
	Vector2* playerSpawnPosition = new Vector2(10, 10);
	player = new Player(*playerSpawnPosition, 1, 1, 1, 1, inputHandler);
    AddEntity(player);
    entities[validEntityCount-1]->isActive = true;

    AddEntity(new BatEnemy(Vector2(20, 20)));
    entities[validEntityCount-1]->isActive = true;
}

void GameManager::AddEntity(Entity *entity) {
    entities[validEntityCount] = entity;
    validEntityCount++;
}

void GameManager::SetActiveLastEntity(bool val) {
    entities[validEntityCount-1]->isActive = val;
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






