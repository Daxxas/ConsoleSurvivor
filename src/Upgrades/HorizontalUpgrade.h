//
// Created by Jacques on 28/09/2022.
//

#ifndef CONSOLESURVIVOR_HORIZONTALUPGRADE_H
#define CONSOLESURVIVOR_HORIZONTALUPGRADE_H


#include "Upgrade.h"

class HorizontalUpgrade : public Upgrade {
public:
    HorizontalUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_HORIZONTALUPGRADE_H
