#include "Shooter.h"

Bullet* Shooter::GetBullet() {
    if(bullets.empty()) {
        Bullet* bullet = CreateBullet();
        bullet->isActive = true;
        GameManager::Instance()->AddEntity(bullet);
        return bullet;
    }
    else {
        Bullet* bullet = bullets.front();
        bullet->isActive = true;
        bullets.pop_front();
        return bullet;
    }
}

void Shooter::ReturnBullet(Bullet* bullet) {
    bullet->Reset();
    bullets.push_back(bullet);
}