//
// Created by Jacques on 27/09/2022.
//

#include "HorizontalShooter.h"
#include "../GameManager.h"

HorizontalShooter::HorizontalShooter() {
    this->shotSpeed = 0;
}

void HorizontalShooter::Shoot() {
    Bullet* bullet = GetBullet();
    bullet->direction = Vector2(1, 0);
    bullet->position = *GameManager::Instance()->GetPlayerPosition();


    Bullet* bullet2 = GetBullet();
    bullet2->direction = Vector2(-1, 0);
    bullet2->position = *GameManager::Instance()->GetPlayerPosition();
}

Bullet * HorizontalShooter::CreateBullet() {
    Vector2 *dir =  new Vector2(0, 0);
    Bullet *bullet = new Bullet(this, *GameManager::Instance()->GetPlayerPosition(), *dir, 1, 0);
    GameManager::Instance()->AddEntity(bullet);

    return bullet;
}