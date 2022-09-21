#pragma once

#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Player.h"
#include "Entities/BatEnemy.h"

class GameManager {
	public:
        static const int maxEntities = 100;
        Entity * entities[maxEntities];
        Player * player;
		InputHandler * inputHandler;
		NYTimer timer;
        int validEntityCount = 0;
        int baseMsBetweenPlayerMovements = 250;
public:
    void RunGameLoop();
    void AddEntity(Entity * entity);

//Singleton pattern
public:
    static GameManager& Instance() {
        static GameManager S;
        return S;
    }

private:
    GameManager();
    ~GameManager();
};