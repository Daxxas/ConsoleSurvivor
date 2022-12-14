#pragma once

#include "MoveSpeedUpgrade.h"
#include "../GameManager.h"

MoveSpeedUpgrade::MoveSpeedUpgrade() {

    level = 0;

    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            " ___    ",
            "/___\\    ",
            "|   |__ ",
            "|______) "
    };

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];

    for (int i = 0; i < spriteHeight; ++i) {
        for (int j = 0; j < spriteWidth; ++j) {
            sprite[i * spriteWidth + j].Char.UnicodeChar = lines[i][j];
            sprite[i * spriteWidth + j].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
    }

    name = "Move Speed++";
}

void MoveSpeedUpgrade::ApplyUpgrade() {
    GameManager::Instance()->player->moveSpeed += 0.1f;
    level++;
}