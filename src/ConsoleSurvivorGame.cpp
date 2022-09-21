#include <windows.h>
#include <stdio.h>
#include <string>
#include "NYTimer.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "ConsoleSurvivorGame.h"
#include <WinUser.h>
#include "GameManager.h"
#include "Renderer.h"

using namespace std;

ConsoleSurvivorGame::ConsoleSurvivorGame(){
    this->timer = NYTimer();
}

void ConsoleSurvivorGame::launchGame() {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleSurvivorGame::PrepareWindowStyle(hOutput);

    Renderer *renderer = new Renderer(hOutput);

    this->timer.start();
    int sleepTime = 0;
    unsigned long loopDurationMs;
    bool gameIsRunning = true;
	
    while(gameIsRunning) {
        this->timer.getElapsedMs(true);

        GameManager::Instance().RunGameLoop();
        renderer->Render();

        loopDurationMs = this->timer.getElapsedMs(true);

        sleepTime = MS_PER_GAME_TICK - loopDurationMs;

        if (sleepTime >= 0) {
            Sleep(sleepTime);
        }
        else {
            // Less than 60fps
        }
    }
}



void ConsoleSurvivorGame::HideCaret(HANDLE hOutput) {
    // Hide Caret
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOutput, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(hOutput, &cursorInfo);
}

void ConsoleSurvivorGame::PrepareWindowStyle(HANDLE hOutput) {
    HWND hwnd_console = GetConsoleWindow();
    ShowWindow(hwnd_console, SW_MAXIMIZE);

    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOutput, &scrBufferInfo);

    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;

    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    // set the new screen buffer dimensions
    SetConsoleScreenBufferSize(hOutput, newSize);
    HideCaret(hOutput);
}
