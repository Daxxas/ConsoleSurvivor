//
// Created by Jacques on 28/09/2022.
//

#include "VerticalShooter.h"
#include "../GameManager.h"

VerticalShooter::VerticalShooter() {
    this->shotSpeed = 0;
}

void VerticalShooter::Shoot() {
    Bullet* bullet = GetBullet();
    bullet->direction = Vector2(0, 1);
    bullet->position = *GameManager::Instance()->GetPlayerPosition();


    Bullet* bullet2 = GetBullet();
    bullet2->direction = Vector2(0, -1);
    bullet2->position = *GameManager::Instance()->GetPlayerPosition();
}

Bullet * VerticalShooter::CreateBullet() {
    Vector2 *dir =  new Vector2(0, 0);
    Bullet *bullet = new Bullet(this, *GameManager::Instance()->GetPlayerPosition(), *dir, 1, 0);
    GameManager::Instance()->AddEntity(bullet);

    return bullet;
}