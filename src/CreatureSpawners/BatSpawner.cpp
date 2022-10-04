#include "BatSpawner.h"
#include "../GameManager.h"

BatSpawner::BatSpawner() : CreatureSpawner() {
	spawnTimer.start();
}

void BatSpawner::SpawnEnemies() {
	GameManager* gm = GameManager::Instance();
	float diff = gm->GetCurrentDifficulty();
	if (spawnTimer.getElapsedMs(false) > (float)baseMsBetweenSpawns/diff) {
		// generate coords
		Vector2* playerPos = gm->GetPlayerPosition();
		bool hasSpawned = false;
		while (!hasSpawned) {
			int randomHeight = rand() % (gm->ARENA_HEIGHT-3) + 3;
			int randomWidth = rand() % (gm->ARENA_WIDTH-3) + 3;
			Vector2 distanceFromPlayer = Vector2(randomWidth, randomHeight) - *playerPos;
			
			std::wstring s = std::to_wstring(distanceFromPlayer.GetMag());
			OutputDebugString(s.c_str());
			
			if (distanceFromPlayer.GetMag() > minDistanceFromPlayer 
				|| distanceFromPlayer.GetMag() < maxDistanceFromPlayer) {
				std::wstring s = std::to_wstring(randomWidth);
				OutputDebugString(s.c_str());
				BatEnemy* bat = new BatEnemy(Vector2(randomWidth, randomHeight), 1, 1, 1, 1);
				gm->AddEntity(bat);
				gm->entities[gm->validEntityCount - 1]->isActive = true;
				gm->enemies[gm->aliveEnemiesCount] = bat;
				gm->aliveEnemiesCount++;
				
				hasSpawned = true;
				spawnTimer.getElapsedMs(true);
			}
		}
	}
}