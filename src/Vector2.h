#pragma once

#ifndef CONSOLESURVIVOR_VECTOR2_H
#define CONSOLESURVIVOR_VECTOR2_H

#include <math.h>

struct Vector2 {
public:
    int x;
    int y;
	
public:
    Vector2(int x, int y);
    Vector2();
	
    Vector2 add(Vector2&);
    Vector2 multiply(int);
    Vector2 multiply(int, int);
    float GetMag();
    void normalize();

    Vector2 operator-(Vector2& other);
    Vector2& operator-=(Vector2& other);
    bool operator==(Vector2& other);
};
#endif