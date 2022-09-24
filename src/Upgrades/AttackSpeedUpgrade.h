//
// Created by daxxas on 24/09/2022.
//

#ifndef CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H
#define CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H


#include "Upgrade.h"
#include "../GameManager.h"

class AttackSpeedUpgrade : public Upgrade {

public:
    AttackSpeedUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H
