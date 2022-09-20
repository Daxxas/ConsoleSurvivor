#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"
#include <windows.h>

GameManager::GameManager() {
	player = new Player(Vector2(10, 10), 1, 1);
    player->isActive = true;
    entities[0] = player;
    validEntityCount++;
}

void GameManager::RunGameLoop() {
	Vector2* direction = this->inputHandler.DetectMovementDirectionFromPlayer();
	
	// manage player direction
	// manage entities movement
	// manage shooting
}






