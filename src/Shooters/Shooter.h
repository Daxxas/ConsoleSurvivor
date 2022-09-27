#ifndef CONSOLESURVIVOR_SHOOTER_H
#define CONSOLESURVIVOR_SHOOTER_H

#include <list>
#include "../Entities/Bullet.h"

class Bullet;

class Shooter {
private:
    std::list<Bullet*> bullets;
public:
    virtual void Shoot() = 0;
    virtual Bullet* GetBullet();
    virtual void ReturnBullet(Bullet* bullet);
    virtual Bullet* CreateBullet() = 0;
};


#endif //CONSOLESURVIVOR_SHOOTER_H
