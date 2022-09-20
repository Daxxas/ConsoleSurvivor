#include <windows.h>
#include "Vector2.h"
#include "InputHandler.h"

InputHandler::InputHandler() {
}

Vector2* InputHandler::DetectMovementDirectionFromPlayer() {
	// 0x5A : V - 0x51 : Q - 0x53 : S - 0x43 : D
	bool isZPressed = IsVKeyPressed(0x5A);
	bool isQPressed = IsVKeyPressed(0x51);
	bool isSPressed = IsVKeyPressed(0x53);
	bool isDPressed = IsVKeyPressed(0x43);

	return new Vector2(isDPressed - isQPressed, isZPressed - isSPressed);;
}

bool InputHandler::IsVKeyPressed(int vKey) {
	return GetAsyncKeyState(vKey) & 1000000000000000;
}