#ifndef CONSOLESURVIVOR_MOVESPEEDUPGRADE_H
#define CONSOLESURVIVOR_MOVESPEEDUPGRADE_H

#include "Upgrade.h"

class MoveSpeedUpgrade : public Upgrade {
public:
    MoveSpeedUpgrade();
    void ApplyUpgrade() override;
};


#endif //CONSOLESURVIVOR_MOVESPEEDUPGRADE_H
