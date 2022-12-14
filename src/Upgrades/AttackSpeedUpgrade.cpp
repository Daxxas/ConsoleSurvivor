#include "AttackSpeedUpgrade.h"
#include "../GameManager.h"

AttackSpeedUpgrade::AttackSpeedUpgrade() {

    level = 0;

    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            "_______ ",
            "|      O",
            "|  |/_/ ",
            "|__|    "
    };

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];

    for (int i = 0; i < spriteHeight; ++i) {
        for (int j = 0; j < spriteWidth; ++j) {
            sprite[i * spriteWidth + j].Char.UnicodeChar = lines[i][j];
            sprite[i * spriteWidth + j].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
    }

    name = "Attack speed++";
}

void AttackSpeedUpgrade::ApplyUpgrade() {
    GameManager::Instance()->player->shooters[0]->shotSpeed += 0.1f;
    level++;
}