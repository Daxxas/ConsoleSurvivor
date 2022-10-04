//
// Created by Jacques on 28/09/2022.
//

#include "VerticalUpgrade.h"
#include "../GameManager.h"

VerticalUpgrade::VerticalUpgrade() {

    level = 0;

    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            "        ",
            "  /\\    ",
            "  o     ",
            "  \\/    "
    };

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];

    for (int i = 0; i < spriteHeight; ++i) {
        for (int j = 0; j < spriteWidth; ++j) {
            sprite[i * spriteWidth + j].Char.UnicodeChar = lines[i][j];
            sprite[i * spriteWidth + j].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
    }

    name = "Horiz. Shoot++";
}

void VerticalUpgrade::ApplyUpgrade() {
    if(level == 0) {
        GameManager::Instance()->player->shooters[2]->shotSpeed = 1;
    }
    else {
        GameManager::Instance()->player->shooters[2]->shotSpeed += 0.1f;
    }
    level++;
}