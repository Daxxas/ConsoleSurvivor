//
// Created by Jacques on 19/09/2022.
//

#include "Vector2.h"

Vector2::Vector2() {
    x = 0;
    y = 0;
}

Vector2::Vector2(int x, int y) {
    this->x = x;
    this->y = y;
}

float Vector2::GetMag() {
    return sqrt(x * x + y * y);
}

void Vector2::normalize() {
    int newX, newY;
    // normalize vector
    double mag = sqrt(x * x + y * y);
    if (mag == 0) {
        newX = newY = 0;
    }
    else {
	newX = floor((x / mag) + 0.5);
    newY = floor((y / mag) + 0.5);
    }
    x = newX;
	y = newY;
}

Vector2 Vector2::add(Vector2 &other)
{
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(Vector2 &other) {
    return Vector2(this->x - other.x, this->y - other.y);
}
Vector2& Vector2::operator-=(Vector2 &other) {

    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2 Vector2::multiply(int multiplier)
{
    return Vector2(this->x * multiplier, this->y * multiplier);
}

Vector2 Vector2::multiply(int multX, int multY)
{
    return Vector2(this->x * multX, this->y * multY);
}