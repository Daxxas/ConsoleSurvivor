#pragma once
#include "NYTimer.h"
#include "InputHandler.h"
#include "GameManager.h"
#include "Entities/Player.h"
#include <random>

class Renderer {
public:
    static const int DISPLAY_WIDTH = 211;
    static const int DISPLAY_HEIGHT = 50;
    void Render();
    Renderer(HANDLE&);
    Vector2 cameraPosition;
private:
    void CleanBuffer();
    CHAR_INFO buffer[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    CHAR_INFO * groundDeco[GameManager::ARENA_HEIGHT][GameManager::ARENA_WIDTH];
    HANDLE hOutput;
    void DisplayArena(Vector2 cameraTopLeft);
    void DrawUI();
    GameManager *gameManager;
};
