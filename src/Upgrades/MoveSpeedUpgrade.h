#ifndef CONSOLESURVIVOR_MOVESPEEDUPGRADE_H
#define CONSOLESURVIVOR_MOVESPEEDUPGRADE_H

#include "../GameManager.h"
#include "Upgrade.h"

class MoveSpeedUpgrade : public Upgrade {
public:
    int level = 0;
    MoveSpeedUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_MOVESPEEDUPGRADE_H