#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"
#include <windows.h>

GameManager::GameManager() {

}

void GameManager::RunGameLoop() {
	Vector2* direction = this->inputHandler.DetectMovementDirectionFromPlayer();
	
	// manage player direction
	// manage entities movement
	// manage shooting
}






