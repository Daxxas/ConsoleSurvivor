#include <windows.h>
#include "Vector2.h"
#include "NYTimer.h"
#include "InputHandler.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "GameManager.h"
#include "Renderer.h"

Renderer::Renderer(HANDLE hOutput) {
    this->hOutput = hOutput;
    gameManager = &GameManager::Instance();
}

void Renderer::Render() {
    COORD dwBufferSize = {DISPLAY_WIDTH, DISPLAY_HEIGHT};
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = {0, 0, DISPLAY_WIDTH - 1, DISPLAY_HEIGHT - 1 };
    ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,dwBufferCoord, &rcRegion);

    DisplayArena();

    for(int i = 0 ; i < gameManager->validEntityCount; ++i) {

        if(gameManager->entities[i]->isActive) {
            CHAR_INFO* spriteToDisplay = gameManager->entities[i]->Display();

            int yOffset = 0;
            int xOffset = 0;
            for (int j = 0; j < gameManager->entities[i]->spriteWidth * gameManager->entities[i]->spriteHeight; ++j) {

                if(xOffset >= gameManager->entities[i]->spriteWidth) {
                    yOffset++;
                    xOffset = 0;
                }
//                buffer[gameManager->entities[i]->position.y+yOffset][gameManager->entities[i]->position.x+xOffset] = spriteToDisplay[j];
                buffer[gameManager->entities[i]->position.y+yOffset][gameManager->entities[i]->position.x+xOffset] = spriteToDisplay[j];
                xOffset++;
            }
        }

    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
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
            buffer[i][j].Char.AsciiChar = ' ';

            buffer[i][j].Attributes = 0x0005;
        }
    }
}