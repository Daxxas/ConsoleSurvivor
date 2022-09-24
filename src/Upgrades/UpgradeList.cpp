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
    for (int i = 0; i < upgradesCount; i++) {
        weigthsum += weights[i];
    }

    for (int i = 0; i < choiceCount; i++) {
        int random = rand() % weigthsum;
        int currentWeight = 0;
        for (int j = 0; j < upgradesCount; j++) {
            currentWeight += weights[j];
            if (random < currentWeight) {
                currentUpgrades[i] = upgrades[j];
                break;
            }
        }
    }
}