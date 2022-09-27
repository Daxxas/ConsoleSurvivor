#pragma once

#include "NYTimer.h"
#include "Vector2.h"
#include "Upgrades/UpgradeList.h"
#include "InputHandler.h"
#include "Entities/Player.h"
#include "Entities/BatEnemy.h"
#include "Entities/Bullet.h"
#include "CreatureSpawners/CreatureSpawner.h"
#include "CreatureSpawners/BatSpawner.h"

class Player;
class UpgradeList;
class CreatureSpawner;
class BatSpawner;

class GameManager {
//Singleton pattern
private:
    static GameManager *instance;
    GameManager();
    ~GameManager();
public:
    static GameManager* Instance();

public:
    static const int ARENA_WIDTH = 300;
    static const int ARENA_HEIGHT = 300;
    static const int xOffset = 2;
    static const int yOffset = 1;
    static const int maxEnemies = 100;
    static const int maxSpawners = 10;
    static const int maxEntities = 700 + maxEnemies;
    Entity * entities[maxEntities];
    Creature * enemies[maxEnemies];
    CreatureSpawner* spawners[maxSpawners];
    Player * player;
	InputHandler * inputHandler;
    int validEntityCount = 0;
    int aliveEnemiesCount = 0;
    int spawnerCount = 0;
    bool pause = false;
    NYTimer *inputMenuTimer;
    NYTimer *difficultyTimer;
    float difficulty;
    float startDifficulty = 1;
    float maxDifficulty = 5;
    float timestampForMaxDifficultySec = 600;
public:
    int selectedUpgradeIndex = 0;
    UpgradeList *upgradeList;
    void RunGameLoop();
    void AddEntity(Entity * entity);
    void SpawnEnemy();
    void SpawnBat(Vector2&, int, int, int, int);
    void ManageSpawners();
	Vector2* GetPlayerPosition();
    Vector2 GetNearestEnemyPosition();
    float GetCurrentDifficulty();
    void UpdateDifficulty();
    void SetActiveLastEntity(bool val);
};