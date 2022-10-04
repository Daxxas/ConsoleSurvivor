#pragma once
#ifndef CONSOLESURVIVOR_UWUSPAWNER_H
#define CONSOLESURVIVOR_UWUSPAWNER_H

#include "../NYTimer.h"
#include <iostream>
#include <list>
#include "CreatureSpawner.h"

class UwUSpawner : public CreatureSpawner {
protected:
    int baseMsBetweenSpawns = 2000;
public:
    UwUSpawner();
    void SpawnEnemies();
};


#endif
