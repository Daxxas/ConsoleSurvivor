#ifndef CONSOLESURVIVOR_MINE_H
#define CONSOLESURVIVOR_MINE_H


#include "Bullet.h"

class Mine : public Bullet {
public:
    Mine(Shooter* shooter, Vector2& position, Vector2& direction, int damage, float speed);
};


#endif //CONSOLESURVIVOR_MINE_H
