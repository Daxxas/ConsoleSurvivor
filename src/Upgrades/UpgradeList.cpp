//
// Created by Jacques on 23/09/2022.
//

#include "UpgradeList.h"

UpgradeList::UpgradeList() {
    upgrades[0] = new MoveSpeedUpgrade();
    weights[0] = 10;
    upgrades[1] = new AttackSpeedUpgrade();
    weights[1] = 10;

}

void UpgradeList::RefreshUpgrades() {

    for (int i = 0; i < choiceCount; i++) {
        int weigthsum = 0;
        for (int j = 0; j < upgradesCount; j++) {
            weigthsum += weights[j];
        }

        int random = rand() % weigthsum;
        int currentWeight = 0;

        for (int j = 0; j < upgradesCount; j++) {
            if (random < weights[j]) {
                currentUpgrades[i] = upgrades[j];
                break;
            }
            random -= weights[j];
        }
    }
}