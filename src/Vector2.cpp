//
// Created by Jacques on 19/09/2022.
//

#include "Vector2.h"

Vector2::Vector2(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::add(Vector2 other)
{
    return Vector2(this->x + other.x, this->y + other.y);
}