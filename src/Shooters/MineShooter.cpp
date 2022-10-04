//
// Created by Jacques on 04/10/2022.
//

#include "MineShooter.h"
#include "../GameManager.h"

MineShooter::MineShooter() {
    this->shotSpeed = 0;
}

void MineShooter::Shoot() {
    Bullet* bullet = GetBullet();
    bullet->position = *GameManager::Instance()->GetPlayerPosition();
}

Bullet * MineShooter::CreateBullet() {
    Vector2 *dir =  new Vector2(0, 0);
    Bullet *bullet = new Mine(this, *GameManager::Instance()->GetPlayerPosition(), *dir, 1, 0);
    GameManager::Instance()->AddEntity(bullet);

    return bullet;
}