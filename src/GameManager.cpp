#include "GameManager.h"

GameManager::GameManager() {
	inputHandler = new InputHandler();
    inputMenuTimer = new NYTimer();
	Vector2* playerSpawnPosition = new Vector2(ARENA_WIDTH/2, ARENA_HEIGHT/2);
	player = new Player(*playerSpawnPosition, 1, 1, 1, 1, inputHandler);
    upgradeList = new UpgradeList();
    AddEntity(player);
    entities[validEntityCount-1]->isActive = true;

    SpawnEnemy();
    inputMenuTimer->start();
}

void GameManager::AddEntity(Entity *entity) {
    entities[validEntityCount] = entity;
    validEntityCount++;
}

void GameManager::SpawnEnemy() {
    Vector2 batpos = Vector2(20, 20);
    SpawnBat(batpos, 1, 1, 1, 1);
}

void GameManager::SpawnBat(Vector2& spawnPos, int maxHealth, int damage, int attacksPerSecond, int moveSpeed) {
    BatEnemy* bat = new BatEnemy(spawnPos, maxHealth, damage, attacksPerSecond, moveSpeed);
    AddEntity(bat);
    entities[validEntityCount - 1]->isActive = true;
    enemies[aliveEnemiesCount] = bat;
    aliveEnemiesCount++;
}

void GameManager::SetActiveLastEntity(bool val) {
    entities[validEntityCount-1]->isActive = val;
}

void GameManager::RunGameLoop() {
    inputHandler->Update();

    if(!pause) {
        for (int i = 0; i < validEntityCount; ++i) {
            if(entities[i]->isActive) {
                entities[i]->Update();
            }
        }
    }
    else {
        Vector2 direction = inputHandler->DetectReleaseDirection();

        if(direction.x == 1 || direction.x == -1) {
            selectedUpgradeIndex += direction.x;
            if(selectedUpgradeIndex == -1) {
                selectedUpgradeIndex = upgradeList->choiceCount-1;
            }
            selectedUpgradeIndex = selectedUpgradeIndex % upgradeList->choiceCount;
        }

        if(inputHandler->IsVKeyReleased(VK_SPACE)) {
            upgradeList->currentUpgrades[selectedUpgradeIndex]->ApplyUpgrade();
            pause = false;
            player->playerLeveledUp = false;
        }
    }

}

Vector2* GameManager::GetPlayerPosition() {
    Vector2* playerPosition = &player->GetPosition();
	return playerPosition;
}

// Unused
Vector2 GameManager::GetNearestEnemyPosition() {
    if (aliveEnemiesCount == 0) {
        Vector2 up = Vector2(0, 0);
        return up;
    }
	
    Vector2 playerPos = player->position;
	
    float distanceToPlayer = INT_MAX;
    int indexOfNearestEnemy = 0;
	
    for (int i = 0; i < aliveEnemiesCount; i++) {
        if ((enemies[i]->position - playerPos).GetMag() < distanceToPlayer) {
            distanceToPlayer = (enemies[i]->position - playerPos).GetMag();
            indexOfNearestEnemy = i;
        }
    }

    return Vector2(enemies[indexOfNearestEnemy]->position.x, enemies[indexOfNearestEnemy]->position.y);
}

GameManager* GameManager::Instance() {
    if(instance == nullptr) {
        instance = new GameManager();
    }
    return instance;
}

GameManager * GameManager::instance = nullptr;

GameManager::~GameManager() = default;






