#include <windows.h>

#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/BatEnemy.h"
#include "GameManager.h"

GameManager::GameManager() {
	inputHandler = new InputHandler();
	Vector2* playerSpawnPosition = new Vector2(10, 10);
	player = new Player(*playerSpawnPosition, 1, 1, 1, 1);
    AddEntity(player);

    AddEntity(new BatEnemy(Vector2(20, 20)));
	timer.start();
}

void GameManager::AddEntity(Entity *entity) {
    entities[validEntityCount] = entity;
    entities[validEntityCount]->isActive = true;
    validEntityCount++;
}

void GameManager::RunGameLoop() {
	Vector2* direction = this->inputHandler->DetectMovementDirectionFromPlayer();

    for (int i = 0; i < validEntityCount; ++i) {
        if(entities[i]->isActive) {
            entities[i]->Update();
        }
    }

    if (this->timer.getElapsedMs(false) > baseMsBetweenPlayerMovements/player->GetMoveSpeed()) {
        if (direction->x != 0 || direction->y != 0) {
            player->Move(*direction);
            this->timer.getElapsedMs(true);
        }
    }
	// manage player direction
	// manage entities movement
	// manage shooting
}

GameManager::~GameManager() = default;






