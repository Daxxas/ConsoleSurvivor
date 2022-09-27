//
// Created by Jacques on 27/09/2022.
//

#ifndef CONSOLESURVIVOR_HORIZONTALSHOOTER_H
#define CONSOLESURVIVOR_HORIZONTALSHOOTER_H


#include "Shooter.h"

class HorizontalShooter : public Shooter {
    void Shoot() override;
    Bullet* CreateBullet() override;
};


#endif //CONSOLESURVIVOR_HORIZONTALSHOOTER_H
