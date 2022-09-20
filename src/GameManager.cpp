#include <windows.h>

#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"

GameManager::GameManager() {
	inputHandler = new InputHandler();
	player = new Player(Vector2(10, 10), 1, 1, 1, 1);
    player->isActive = true;
    entities[0] = player;
    validEntityCount++;
	timer->start();
}

void GameManager::RunGameLoop() {
	Vector2* direction = this->inputHandler->DetectMovementDirectionFromPlayer();
	
	// todo avec le timer empêcher déplacement
	player->Move(*direction);

	// manage player direction
	// manage entities movement
	// manage shooting
}






