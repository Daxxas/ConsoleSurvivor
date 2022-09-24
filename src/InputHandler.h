#pragma once
#include <windows.h>
#include "Vector2.h"
#include <map>

class InputHandler {
public:
    InputHandler();
    Vector2 GetMovementDirection();
    Vector2 DetectMovementDirectionFromPlayer();
    Vector2 DetectReleaseDirection();
    std::map<int, bool> keyPressedMap;
    bool IsVKeyPressed(int);
    bool IsVKeyReleased(int);
    void Update();
};