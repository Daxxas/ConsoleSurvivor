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
    static const int maxEntities = 800;
    Entity * entities[maxEntities];
    Player * player;
	InputHandler * inputHandler;
    int validEntityCount = 0;
public:
    void RunGameLoop();
    void AddEntity(Entity * entity);
	Vector2* GetPlayerPosition();
    void SetActiveLastEntity(bool val);
};