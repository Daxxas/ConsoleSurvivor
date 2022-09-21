#pragma once

#include "Entity.h"
#include "../GameManager.h"

class BatEnemy : public Entity {
public:
    BatEnemy(Vector2& position);
    void Update() override;
    void Move(Vector2&) override;

};