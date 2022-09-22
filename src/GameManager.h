#pragma once

#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Player.h"
#include "Entities/BatEnemy.h"
#include "Entities/Bullet.h"

class Player;
class GameManager {
//Singleton pattern
public:
    static GameManager& Instance() {
        static GameManager S;
        return S;
    }
private:
    GameManager();
    ~GameManager();

public:
    static const int ARENA_WIDTH = 300;
    static const int ARENA_HEIGHT = 300;
    static const int xOffset = 2;
    static const int yOffset = 1;
    static const int maxEnemies = 100;
    static const int maxEntities = 700 + maxEnemies;
    Entity * entities[maxEntities];
    Entity * enemies[maxEnemies];
    Player * player;
	InputHandler * inputHandler;
    int validEntityCount = 0;
    int aliveEnemiesCount = 0;
public:
    void RunGameLoop();
    void AddEntity(Entity * entity);
    void SpawnEnemy();
    void SpawnBat(Vector2&, int, int, int, int);
	Vector2* GetPlayerPosition();
    Vector2 GetNearestEnemyPosition();
    void SetActiveLastEntity(bool val);
};