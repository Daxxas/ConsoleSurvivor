#pragma once
#ifndef CONSOLESURVIVOR_BATSPAWNER_H
#define CONSOLESURVIVOR_BATSPAWNER_H

#include "../NYTimer.h"
#include <iostream>
#include <list>
#include "CreatureSpawner.h"

class BatSpawner : public CreatureSpawner {
protected:
    int baseMsBetweenSpawns = 2000;
public:
    BatSpawner();
    void SpawnEnemies();
};


#endif
