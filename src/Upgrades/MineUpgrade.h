//
// Created by Jacques on 04/10/2022.
//

#ifndef CONSOLESURVIVOR_MINEUPGRADE_H
#define CONSOLESURVIVOR_MINEUPGRADE_H


#include "Upgrade.h"

class MineUpgrade : public Upgrade {
public:
    MineUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_MINEUPGRADE_H
