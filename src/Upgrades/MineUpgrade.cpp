//
// Created by Jacques on 04/10/2022.
//

#include "MineUpgrade.h"
#include "../GameManager.h"

MineUpgrade::MineUpgrade() {

    level = 0;

    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            "  ____  ",
            " |    |",
            "/------\\",
            "|______|"
    };

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];

    for (int i = 0; i < spriteHeight; ++i) {
        for (int j = 0; j < spriteWidth; ++j) {
            sprite[i * spriteWidth + j].Char.UnicodeChar = lines[i][j];
            sprite[i * spriteWidth + j].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
    }

    name = "Miner++";
}

void MineUpgrade::ApplyUpgrade() {
    if(level == 0) {
        GameManager::Instance()->player->shooters[3]->shotSpeed = 1;
    }
    else {
        GameManager::Instance()->player->shooters[3]->shotSpeed += 0.1f;
    }
    level++;
}