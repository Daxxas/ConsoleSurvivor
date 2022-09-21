#pragma once
#include "NYTimer.h"
#include "InputHandler.h"
#include "Entities/Player.h"
#include "GameManager.h"

class Renderer {
public:
    static const int DISPLAY_WIDTH = 300;
    static const int DISPLAY_HEIGHT = 50;
    void Render();
    Renderer(HANDLE&);
    Vector2 cameraPosition;
private:
    void CleanBuffer();
    CHAR_INFO buffer[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    HANDLE hOutput;
    void DisplayArena(Vector2 cameraTopLeft, Vector2 cameraBottomRight);
    GameManager* gameManager;
};
