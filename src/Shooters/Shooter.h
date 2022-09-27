#ifndef CONSOLESURVIVOR_SHOOTER_H
#define CONSOLESURVIVOR_SHOOTER_H

#include <list>
#include "../Entities/Bullet.h"
#include "../NYTimer.h"

class Bullet;

class Shooter {
private:
    std::list<Bullet*> bullets;
    NYTimer localTimer;
public:
    int baseMsBetweenShots = 500;
    int shotSpeed = 1;
    virtual void Shoot() = 0;
    virtual void Update();
    virtual Bullet* GetBullet();
    virtual void ReturnBullet(Bullet* bullet);
    virtual Bullet* CreateBullet() = 0;
};


#endif //CONSOLESURVIVOR_SHOOTER_H
