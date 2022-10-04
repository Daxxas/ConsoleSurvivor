#include "UwUSpawner.h"
#include "../GameManager.h"

UwUSpawner::UwUSpawner() : CreatureSpawner() {
	spawnTimer.start();
}

void UwUSpawner::SpawnEnemies() {
	GameManager* gm = GameManager::Instance();
	float diff = gm->GetCurrentDifficulty();
	if (spawnTimer.getElapsedMs(false) > (float)baseMsBetweenSpawns / diff) {
		// generate coords
		Vector2* playerPos = gm->GetPlayerPosition();
		bool hasSpawned = false;
		while (!hasSpawned) {
			int randomHeight = rand() % (gm->ARENA_HEIGHT - 3) + 3;
			int randomWidth = rand() % (gm->ARENA_WIDTH - 3) + 3;
			Vector2 distanceFromPlayer = Vector2(randomWidth, randomHeight) - *playerPos;

			std::wstring s = std::to_wstring(distanceFromPlayer.GetMag());
			OutputDebugString(s.c_str());

			if (distanceFromPlayer.GetMag() > minDistanceFromPlayer
				|| distanceFromPlayer.GetMag() < maxDistanceFromPlayer) {
				std::wstring s = std::to_wstring(randomWidth);
				OutputDebugString(s.c_str());
				UwUEnemy* uwu = new UwUEnemy(Vector2(randomWidth, randomHeight), 1, 1, 1, 1);
				gm->AddEntity(uwu);
				gm->entities[gm->validEntityCount - 1]->isActive = true;
				gm->enemies[gm->aliveEnemiesCount] = uwu;
				gm->aliveEnemiesCount++;

				hasSpawned = true;
				spawnTimer.getElapsedMs(true);
			}
		}
	}
}