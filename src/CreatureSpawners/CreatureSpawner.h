#pragma once

#include <windows.h>
#include <string>
#include <random>
#include "../NYTimer.h"

class CreatureSpawner {
public:
    CreatureSpawner();
    virtual void SpawnEnemies() = 0;
protected:
    int baseMsBetweenSpawns;
    int minDistanceFromPlayer = 210;
    int maxDistanceFromPlayer = 260;
    NYTimer spawnTimer;
};
