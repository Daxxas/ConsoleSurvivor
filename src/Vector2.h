#pragma once

#ifndef CONSOLESURVIVOR_VECTOR2_H
#define CONSOLESURVIVOR_VECTOR2_H

struct Vector2 {
public:
    Vector2(int x, int y);
    Vector2();
    Vector2 add(Vector2&);
    Vector2 multiply(int);
    Vector2 multiply(int, int);
    void normalize();

    Vector2 operator-(Vector2 &other);
    Vector2& operator-=(Vector2 &other);
    int x;
    int y;
};
#endif