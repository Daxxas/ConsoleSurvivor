#include "Vector2.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"
#include <windows.h>

GameManager::GameManager() {
	//player = new Player(Vector2(0, 0), 1, 1);
}

void GameManager::RunGameLoop() {
	GameManager::DetectLastInputFromPlayer();
}

void GameManager::DetectLastInputFromPlayer() {
	bool isZPressed = IsVKeyPressed(0x5A);
	bool isQPressed = IsVKeyPressed(0x51);
	bool isSPressed = IsVKeyPressed(0x53);
	bool isDPressed = IsVKeyPressed(0x43);
	if (isZPressed || isQPressed || isSPressed || isDPressed) {
		//OutputDebugStringW(L"touche pressée OK");
	}
}

bool GameManager::IsVKeyPressed(int vKey) {
	return GetAsyncKeyState(vKey) & 1000000000000000;
}




