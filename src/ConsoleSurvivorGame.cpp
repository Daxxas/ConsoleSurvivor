#include <iostream>
#include <windows.h>
#include <stdio.h>

#include "ConsoleSurvivorGame.h"
#include "Renderer.h"

using namespace std;

bool gameIsRunning = true;

ConsoleSurvivorGame::ConsoleSurvivorGame(){

}

void ConsoleSurvivorGame::launchGame() {
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleSurvivorGame::PrepareWindowStyle(hOutput);

//    GameManager gameManager;
    Renderer renderer = Renderer(hOutput);

    while(gameIsRunning) {
        renderer.Render();
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
