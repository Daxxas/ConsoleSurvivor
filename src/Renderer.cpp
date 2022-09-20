//
// Created by Jacques on 20/09/2022.
//

#include "Renderer.h"
#include <windows.h>

Renderer::Renderer(HANDLE hOutput) {
    this->hOutput = hOutput;
}

void Renderer::Render() {
    COORD dwBufferSize = {DISPLAY_WIDTH, DISPLAY_HEIGHT};
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = {0, 0, DISPLAY_WIDTH - 1, DISPLAY_HEIGHT - 1 };
    ReadConsoleOutput( hOutput, (CHAR_INFO *)buffer, dwBufferSize,dwBufferCoord, &rcRegion );

    DisplayArena();

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

    Sleep(1000);
}

void Renderer::DisplayArena() {
    for (int i = 0; i < DISPLAY_WIDTH; ++i) {
        buffer[0][i].Char.AsciiChar = '#';
        buffer[DISPLAY_HEIGHT - 1][i].Char.AsciiChar = '#';
    }

    for (int i = 0; i < DISPLAY_HEIGHT; ++i) {
        buffer[i][0].Char.AsciiChar = '#';
        buffer[i][DISPLAY_WIDTH - 1].Char.AsciiChar = '#';
    }

    for (int i = 1; i < DISPLAY_HEIGHT - 1; ++i) {
        for (int j = 1; j < DISPLAY_WIDTH - 1; ++j) {
            buffer[i][j].Char.AsciiChar = '.';

            buffer[i][j].Attributes = 0x0005;
        }
    }
}