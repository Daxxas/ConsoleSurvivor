#include "InputHandler.h"

InputHandler::InputHandler() {
    keyPressedMap[0x5A] = false;
    keyPressedMap[0x51] = false;
    keyPressedMap[0x53] = false;
    keyPressedMap[0x44] = false;
    keyPressedMap[VK_SPACE] = false;
}

void InputHandler::Update() {

    std::map<int,bool>::iterator it = keyPressedMap.begin();
    std::map<int,bool>::iterator end = keyPressedMap.end();

    for (it; it != end; ++it) {
        if(IsVKeyPressed(it->first)) {
            it->second = true;
        }
    }
}

Vector2* InputHandler::DetectMovementDirectionFromPlayer() {
	// 0x5A : V - 0x51 : Q - 0x53 : S - 0x44 : D
	bool isZPressed = IsVKeyPressed(0x5A);
	bool isQPressed = IsVKeyPressed(0x51);
	bool isSPressed = IsVKeyPressed(0x53);
	bool isDPressed = IsVKeyPressed(0x44);

	return new Vector2(isDPressed - isQPressed, isSPressed - isZPressed);;
}

Vector2 InputHandler::DetectReleaseDirection() {
    // 0x5A : V - 0x51 : Q - 0x53 : S - 0x44 : D
    bool isZPressed = IsVKeyReleased(0x5A);
    bool isQPressed = IsVKeyReleased(0x51);
    bool isSPressed = IsVKeyReleased(0x53);
    bool isDPressed = IsVKeyReleased(0x44);

    return Vector2(isDPressed - isQPressed, isSPressed - isZPressed);;

}

bool InputHandler::IsVKeyPressed(int vKey) {
	return GetAsyncKeyState(vKey) & 1000000000000000;
}


bool InputHandler::IsVKeyReleased(int vKey) {
    if(!IsVKeyPressed(vKey) && keyPressedMap[vKey]) {
        keyPressedMap[vKey] = false;
        return true;
    }
    else {
        return false;
    }
}

