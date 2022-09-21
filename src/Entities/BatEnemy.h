#pragma once

#include "Entity.h"

class BatEnemy : public Entity {
public:
    BatEnemy(Vector2& position);
    void Update() override;

};