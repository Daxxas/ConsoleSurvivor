#include "Renderer.h"

Renderer::Renderer(HANDLE& hOutput) {
    this->hOutput = hOutput;
    gameManager = GameManager::Instance();

    for (int y = 0; y < GameManager::ARENA_HEIGHT; ++y) {
        for (int x = 0; x < GameManager::ARENA_WIDTH; ++x) {
            groundDeco[y][x] = new CHAR_INFO();

            int randval = rand() % 200;

            if(randval == 0) {

                groundDeco[y][x]->Char.UnicodeChar = '.';
                groundDeco[y][x]->Attributes = 0x0F;
            }
            else {

                groundDeco[y][x]->Char.UnicodeChar = ' ';
                groundDeco[y][x]->Attributes = 0;
            }

        }
    }
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

    DisplayArena(cameraTopLeft);

    for(int i = 0 ; i < gameManager->validEntityCount; i++) {

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

    DrawUI();

    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    //std::cout << "x:" << gameManager->player->position.x << "- y:" << gameManager->player->position.y;
}

void Renderer::CleanBuffer() {
    for(int i = 0; i < DISPLAY_HEIGHT; ++i) {
        for(int j = 0; j < DISPLAY_WIDTH; ++j) {
            buffer[i][j].Char.UnicodeChar = 0x0;
            buffer[i][j].Attributes = 0x0;
        }
    }
}

void Renderer::DrawUI() {

    // XP BAR
    float xpPercent = (float)gameManager->player->xp / (float)gameManager->player->maxXP;
    int xpBarWidth = (int)(DISPLAY_WIDTH * xpPercent);
    for (int x = 0; x < xpBarWidth; ++x) {
        buffer[0][x].Char.UnicodeChar = 0x2580;
        buffer[0][x].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
    }
    std::string levelText = "Level: " + std::to_string(gameManager->player->level);

    for (int i = 0; i < levelText.length(); ++i) {
        buffer[1][(DISPLAY_WIDTH-levelText.length())/2 + i].Char.UnicodeChar = levelText[i];
        buffer[1][(DISPLAY_WIDTH-levelText.length())/2 + i].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    }

    // Player position
    std::string playerpos = "position: x: ";
    playerpos += std::to_string(gameManager->GetPlayerPosition()->x);
    playerpos += " y: ";
    playerpos += std::to_string(gameManager->GetPlayerPosition()->y);

    for (int i = 0; i < playerpos.length(); ++i) {
        buffer[DISPLAY_HEIGHT-1][i].Char.UnicodeChar = playerpos[i];
        buffer[DISPLAY_HEIGHT-1][i].Attributes = 0x0002;
    }

    if(gameManager->player->playerLeveledUp) {
        int upgradeWidth = 80;
        int upgradeHeight = 20;

        Vector2 topLeft = Vector2((DISPLAY_WIDTH - upgradeWidth) / 2, (DISPLAY_HEIGHT - upgradeHeight) / 2);

        // Borders
        for (int i = 0; i < upgradeHeight; ++i) {
            buffer[i + topLeft.y][topLeft.x].Char.UnicodeChar = '|';
            buffer[i + topLeft.y][topLeft.x].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
        for (int i = 0; i < upgradeHeight; ++i) {
            buffer[i + topLeft.y][(DISPLAY_WIDTH + upgradeWidth)/2 - 1].Char.UnicodeChar = '|';
            buffer[i + topLeft.y][(DISPLAY_WIDTH + upgradeWidth)/2 - 1].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        for (int i = 0; i < upgradeWidth; ++i) {
            buffer[topLeft.y][i + topLeft.x].Char.UnicodeChar = '-';
            buffer[topLeft.y][i + topLeft.x].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        for (int i = 0; i < upgradeWidth; ++i) {
            buffer[(DISPLAY_HEIGHT + upgradeHeight)/2][i + topLeft.x].Char.UnicodeChar = '-';
            buffer[(DISPLAY_HEIGHT + upgradeHeight)/2][i + topLeft.x].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        std::string levelUpText = "Level up!";

        for (int i = 0; i < levelUpText.length(); ++i) {
            buffer[topLeft.y][(DISPLAY_WIDTH-levelUpText.length())/2 + i].Char.UnicodeChar = levelUpText[i];
            buffer[topLeft.y][(DISPLAY_WIDTH-levelUpText.length())/2 + i].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        // Fill the background
        for (int i = 0; i < upgradeHeight - 1; ++i) {
            for (int j = 0; j < upgradeWidth - 2; ++j) {
                buffer[i + topLeft.y + 1][j + topLeft.x + 1].Char.UnicodeChar = ' ';
                buffer[i + topLeft.y + 1][j + topLeft.x + 1].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            }
        }

        // upgrades
        std::string upgradeText = "Choose an upgrade:";
        for (int i = 0; i < upgradeText.length(); ++i) {
            buffer[topLeft.y + 2][(DISPLAY_WIDTH-upgradeText.length())/2 + i].Char.UnicodeChar = upgradeText[i];
            buffer[topLeft.y + 2][(DISPLAY_WIDTH-upgradeText.length())/2 + i].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        for (int i = 0; i < UpgradeList::choiceCount; ++i) {

            WORD upgradeColor = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            if(i == gameManager->selectedUpgradeIndex) {
                upgradeColor = 0x0F;
            }

            Upgrade *currentUpgrade = gameManager->upgradeList->currentUpgrades[i];
            std::string upgradeChoiceName = currentUpgrade->name;
            std::string upgradeLevel = "lvl. " + std::to_string(currentUpgrade->level);
            CHAR_INFO* upgradeSprite = currentUpgrade->sprite;
            int spriteWidth = currentUpgrade->spriteWidth;
            int spriteHeight = currentUpgrade->spriteHeight;

            for (int x = 0; x < spriteWidth; ++x) {
                for (int y = 0; y < spriteHeight; ++y) {
                    buffer[topLeft.y + upgradeHeight/2 - spriteHeight/2 + y][topLeft.x + upgradeWidth/2 - (spriteWidth + 10 + spriteWidth/2) + x + i * (spriteWidth + 10)].Char.UnicodeChar = upgradeSprite[y * spriteWidth + x].Char.UnicodeChar;
                    buffer[topLeft.y + upgradeHeight/2 - spriteHeight/2 + y][topLeft.x + upgradeWidth/2 - (spriteWidth + 10 + spriteWidth/2) + x + i * (spriteWidth + 10)].Attributes = upgradeColor;
                }
            }

            for (int j = 0; j < upgradeChoiceName.length(); ++j) {
                buffer[topLeft.y + upgradeHeight/2 + spriteHeight/2][(DISPLAY_WIDTH-upgradeChoiceName.length())/2 + i * (spriteWidth + 10) + j - 18].Char.UnicodeChar = upgradeChoiceName[j];
                buffer[topLeft.y + upgradeHeight/2 + spriteHeight/2][(DISPLAY_WIDTH-upgradeChoiceName.length())/2 + i * (spriteWidth + 10) + j - 18].Attributes = upgradeColor;
            }

            for (int j = 0; j < upgradeLevel.length(); ++j) {
                buffer[topLeft.y + upgradeHeight/2 + spriteHeight/2 + 1][(DISPLAY_WIDTH-upgradeChoiceName.length())/2 + i * (spriteWidth + 10) + j - 18].Char.UnicodeChar = upgradeLevel[j];
                buffer[topLeft.y + upgradeHeight/2 + spriteHeight/2 + 1][(DISPLAY_WIDTH-upgradeChoiceName.length())/2 + i * (spriteWidth + 10) + j - 18].Attributes = upgradeColor;
            }
        }
    }
}

void Renderer::DisplayArena(Vector2 cameraTopLeft) {

    for (int x = 0; x < DISPLAY_WIDTH; ++x) {
        for (int y = 0; y < DISPLAY_HEIGHT; ++y) {

            if(cameraTopLeft.x + x <= 0 || cameraTopLeft.x + x >= GameManager::ARENA_WIDTH-1 || cameraTopLeft.y + y <= 0 || cameraTopLeft.y + y >= GameManager::ARENA_HEIGHT-1) {
                buffer[y][x].Char.UnicodeChar = '#';
                buffer[y][x].Attributes = 0x0F;
                continue;
            }

            buffer[y][x] = *groundDeco[cameraTopLeft.y + y][cameraTopLeft.x + x];

        }
    }
}