//
// Created by Jacques on 27/09/2022.
//

#ifndef CONSOLESURVIVOR_HORIZONTALSHOOTER_H
#define CONSOLESURVIVOR_HORIZONTALSHOOTER_H


#include "Shooter.h"

class HorizontalShooter : public Shooter {
public:
    void Shoot() override;
    Bullet* CreateBullet() override;
    HorizontalShooter();
};


#endif //CONSOLESURVIVOR_HORIZONTALSHOOTER_H
