#include "HorizontalUpgrade.h"
#include "../GameManager.h"

HorizontalUpgrade::HorizontalUpgrade() {

    level = 0;

    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            "        ",
            "        ",
            "<--o--> ",
            "        "
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

void HorizontalUpgrade::ApplyUpgrade() {
    if(level == 0) {
        GameManager::Instance()->player->shooters[1]->shotSpeed = 1;
    }
    else {
        GameManager::Instance()->player->shooters[1]->shotSpeed += 0.1f;
    }
    level++;
}