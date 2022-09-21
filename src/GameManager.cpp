#include <windows.h>

#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"
#include "Entities/BatEnemy.h"

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

	player->position = player->position.add(*direction); // multiplier par speed
	// manage player direction
	// manage entities movement
	// manage shooting
}

GameManager::~GameManager() = default;






