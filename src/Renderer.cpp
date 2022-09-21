#include "Renderer.h"

Renderer::Renderer(HANDLE& hOutput) {
    this->hOutput = hOutput;
    gameManager = &GameManager::Instance();
}

void Renderer::Render() {
    COORD dwBufferSize = {DISPLAY_WIDTH, DISPLAY_HEIGHT};
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = {0, 0, DISPLAY_WIDTH - 1, DISPLAY_HEIGHT - 1 };
    ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,dwBufferCoord, &rcRegion);

    CleanBuffer();

    cameraPosition = *gameManager->GetPlayerPosition();

    Vector2 cameraTopLeft = Vector2(cameraPosition.x - DISPLAY_WIDTH / 2, cameraPosition.y - DISPLAY_HEIGHT / 2);
    Vector2 cameraBottomRight = Vector2(cameraPosition.x + DISPLAY_WIDTH / 2, cameraPosition.y + DISPLAY_HEIGHT / 2);

    DisplayArena();

    for(int i = 0 ; i < gameManager->validEntityCount; ++i) {

        if(gameManager->entities[i]->isActive) {
            CHAR_INFO* spriteToDisplay = gameManager->entities[i]->Display();
            Vector2 entityPosition = gameManager->entities[i]->position;

            int yOffset = 0;
            int xOffset = 0;
            for (int j = 0; j < gameManager->entities[i]->spriteWidth * gameManager->entities[i]->spriteHeight; ++j) {

                if(xOffset >= gameManager->entities[i]->spriteWidth) {
                    yOffset++;
                    xOffset = 0;
                }

                Vector2 spritePosition = Vector2(entityPosition.x + xOffset, entityPosition.y + yOffset);

                if(spritePosition.x >= cameraTopLeft.x && spritePosition.x <= cameraBottomRight.x && spritePosition.y >= cameraTopLeft.y && spritePosition.y <= cameraBottomRight.y) {
                    int x = spritePosition.x - cameraTopLeft.x;
                    int y = spritePosition.y - cameraTopLeft.y;
                    buffer[y][x] = spriteToDisplay[j];
                }
                xOffset++;
            }
        }
    }

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    //std::cout << "x:" << gameManager->player->position.x << "- y:" << gameManager->player->position.y;
}

void Renderer::CleanBuffer() {
    for(int i = 0; i < DISPLAY_HEIGHT; ++i) {
        for(int j = 0; j < DISPLAY_WIDTH; ++j) {
            buffer[i][j].Char.AsciiChar = ' ';
            buffer[i][j].Attributes = 0;
        }
    }
}

void Renderer::DisplayArena(Vector2 cameraTopLeft, Vector2 cameraBottomRight) {

    // TODO : do the correct math to display the wall when near arena

    for (int x = cameraTopLeft.x; x < DISPLAY_WIDTH; ++x) {
        for (int y = 0; y < DISPLAY_HEIGHT; ++y) {
            if(x == 0 || x == GameManager::ARENA_WIDTH - 1 || y == 0 || y == GameManager::ARENA_HEIGHT - 1) {
                buffer[y][x].Char.AsciiChar = '#';
                buffer[y][x].Attributes = 0x0F;
            }
        }
    }
}