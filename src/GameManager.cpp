#include <windows.h>
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"

GameManager::GameManager() {
	player = new Player(Vector2(10, 10), 1, 1, 1);
    player->isActive = true;
    entities[0] = player;
    validEntityCount++;
}

void GameManager::RunGameLoop() {
	Vector2* direction = this->inputHandler.DetectMovementDirectionFromPlayer();
	
	player->position = player->position.add(*direction); // multiplier par speed
	// manage player direction
	// manage entities movement
	// manage shooting
}






