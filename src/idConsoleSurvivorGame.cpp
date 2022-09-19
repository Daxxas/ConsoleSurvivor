#include <iostream>
#include <windows.h>
#include <stdio.h>

#include "idConsoleSurvivorGame.h"
	        
using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 30;

bool gameIsRunning = false;

int pos_x = SCREEN_WIDTH / 2;
int pos_y = SCREEN_HEIGHT / 2;

CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

HANDLE hStdin;
DWORD fdwSaveOldMode;

idConsoleSurvivorGame::idConsoleSurvivorGame(){
    cout << "Hello World!";
}

void idConsoleSurvivorGame::launchGame() {
    idConsoleSurvivorGame::PrepareWindowStyle();

    gameIsRunning = true;
	
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    HideCaret(hOutput);

    for (int i = 0; i < SCREEN_WIDTH; ++i) {
        buffer[0][i].Char.AsciiChar = '#';
        buffer[SCREEN_HEIGHT - 1][i].Char.AsciiChar = '#';
    }

    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        buffer[i][0].Char.AsciiChar = '#';
        buffer[i][SCREEN_WIDTH - 1].Char.AsciiChar = '#';
    }

    for (int i = 1; i < SCREEN_HEIGHT - 1; ++i) {
        for (int j = 1; j < SCREEN_WIDTH - 1; ++j) {
            buffer[i][j].Char.AsciiChar = '.';
            // Dark charater attribute
            buffer[i][j].Attributes = 0x0005;
        }
    }

    buffer[pos_y][pos_x].Char.AsciiChar = 'O';
    buffer[pos_y][pos_x].Attributes = 0x0001;


    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

    cin.ignore();
}

void idConsoleSurvivorGame::HideCaret(HANDLE hOutput) {
    // Hide Caret
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOutput, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(hOutput, &cursorInfo);
}

void idConsoleSurvivorGame::PrepareWindowStyle() {
    LONG_PTR new_style =  WS_OVERLAPPEDWINDOW;
    HWND hwnd_console = GetConsoleWindow();

    ShowWindow(hwnd_console, SW_MAXIMIZE);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

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
    SetConsoleScreenBufferSize(hOut, newSize);
}

void idConsoleSurvivorGame::KeyEventProc(KEY_EVENT_RECORD ker)
{
    printf("Key event: ");

    if (ker.bKeyDown) {
        pos_y--;
        printf("key pressed\n");
    }
    else printf("key released\n");
}

void idConsoleSurvivorGame::ErrorExit(LPSTR lpszMessage)
{
    fprintf(stderr, "%s\n", lpszMessage);

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0);
}

