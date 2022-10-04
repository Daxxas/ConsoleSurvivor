#pragma once

#ifndef CONSOLESURVIVOR_UPGRADELIST_H
#define CONSOLESURVIVOR_UPGRADELIST_H

#include "Upgrade.h"
#include "AttackSpeedUpgrade.h"
#include "MoveSpeedUpgrade.h"
#include "HorizontalUpgrade.h"
#include "VerticalUpgrade.h"
#include "MineUpgrade.h"
#include <random>

class UpgradeList {
private:
    static const int upgradesCount = 5;
    Upgrade* upgrades[upgradesCount];
    int weights[upgradesCount];
public:
    static const int choiceCount = 3;
    Upgrade* currentUpgrades[choiceCount];
    UpgradeList();
    void RefreshUpgrades();
};


#endif //CONSOLESURVIVOR_UPGRADELIST_H
