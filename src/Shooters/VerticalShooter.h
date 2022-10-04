//
// Created by Jacques on 28/09/2022.
//

#ifndef CONSOLESURVIVOR_VERTICALSHOOTER_H
#define CONSOLESURVIVOR_VERTICALSHOOTER_H


#include "Shooter.h"

class VerticalShooter : public Shooter {
public:
    VerticalShooter();
    void Shoot() override;
    Bullet* CreateBullet() override;
};


#endif //CONSOLESURVIVOR_VERTICALSHOOTER_H
