#include <iostream>
#include <windows.h>

using namespace std;

void HideCaret(HANDLE hOutput);
void KeyEventProc(KEY_EVENT_RECORD);

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 30;

int pos_x = SCREEN_WIDTH / 2;
int pos_y = SCREEN_HEIGHT / 2;



int main() {
    HANDLE hOutput = (HANDLE)GetStdHandle( STD_OUTPUT_HANDLE );
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    COORD dwBufferSize = {SCREEN_WIDTH, SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

    ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

    DWORD fdwMode;

    fdwMode = ENABLE_WINDOW_INPUT;
    SetConsoleMode(hInput, fdwMode);

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


    WriteConsoleOutput( hOutput, (CHAR_INFO *)buffer, dwBufferSize,
                        dwBufferCoord, &rcRegion );


    cin.ignore();
    return 0;
}

void HideCaret(HANDLE hOutput) {
    // Hide Caret
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOutput, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(hOutput, &cursorInfo);
}

void KeyEventProc(KEY_EVENT_RECORD ker)
{
    if(ker.bKeyDown)
        pos_y--;
}