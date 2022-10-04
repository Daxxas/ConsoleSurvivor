//
// Created by Jacques on 04/10/2022.
//

#ifndef CONSOLESURVIVOR_MINESHOOTER_H
#define CONSOLESURVIVOR_MINESHOOTER_H


#include "Shooter.h"
#include "../Entities/Mine.h"

class MineShooter : public Shooter {
public:
    MineShooter();
    void Shoot() override;
    Bullet * CreateBullet() override;
};


#endif //CONSOLESURVIVOR_MINESHOOTER_H
