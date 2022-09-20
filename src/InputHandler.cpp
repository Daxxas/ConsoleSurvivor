//
// Created by Jacques on 19/09/2022.
//

#include <windows.h>
#include "InputHandler.h"

Vector2 InputHandler::GetMovementDirection() {

    short leftKey = GetAsyncKeyState('Q');

    if(leftKey & 0x01) {
        return Vector2(-1, 0);
    }

    return Vector2(0, 0);
}