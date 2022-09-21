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