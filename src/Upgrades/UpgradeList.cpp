//
// Created by Jacques on 23/09/2022.
//

#include "UpgradeList.h"

UpgradeList::UpgradeList() {
    upgrades[0] = new MoveSpeedUpgrade();
    weights[0] = 1;
}

void UpgradeList::RefreshUpgrades() {
    int weigthsum = 0;
    for (int i = 0; i < 1; i++) {
        weigthsum += weights[i];
    }

    for (int i = 0; i < choiceCount; i++) {
        int random = rand() % weigthsum;
        int currentWeight = 0;
        for (int j = 0; j < 1; j++) {
            currentWeight += weights[j];
            if (random < currentWeight) {
                currentUpgrades[i] = upgrades[j];
                break;
            }
        }
    }
}