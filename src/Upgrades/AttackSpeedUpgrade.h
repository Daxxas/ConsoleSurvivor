#ifndef CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H
#define CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H


#include "Upgrade.h"

class AttackSpeedUpgrade : public Upgrade {

public:
    AttackSpeedUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_ATTACKSPEEDUPGRADE_H
