#ifndef CONSOLESURVIVOR_BASICSHOOTER_H
#define CONSOLESURVIVOR_BASICSHOOTER_H

#include "Shooter.h"

class BasicShooter : public Shooter {
public:
    void Shoot() override;
    Bullet * CreateBullet() override;
};


#endif //CONSOLESURVIVOR_BASICSHOOTER_H
