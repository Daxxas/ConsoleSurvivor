//
// Created by Jacques on 28/09/2022.
//

#ifndef CONSOLESURVIVOR_VERTICALUPGRADE_H
#define CONSOLESURVIVOR_VERTICALUPGRADE_H


#include "Upgrade.h"

class VerticalUpgrade : public Upgrade {
public:
    VerticalUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_VERTICALUPGRADE_H
