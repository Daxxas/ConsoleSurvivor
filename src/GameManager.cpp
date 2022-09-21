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
	player = new Player(Vector2(10, 10), 1, 1, 1, 1);
    player->isActive = true;
    entities[0] = player;
    validEntityCount++;

    entities[1] = new BatEnemy(Vector2(20, 20));
    entities[1]->isActive = true;
    validEntityCount++;
	timer.start();
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






