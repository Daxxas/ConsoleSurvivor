#include "MoveSpeedUpgrade.h"

MoveSpeedUpgrade::MoveSpeedUpgrade() {



    spriteWidth = 8;
    spriteHeight = 4;
    std::string lines[4] = {
            " __     ",
            "(  )    ",
            "|  |__  ",
            "|_____) "
    };

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];

    for (int i = 0; i < spriteHeight; ++i) {
        for (int j = 0; j < spriteWidth; ++j) {
            sprite[i * spriteWidth + j].Char.UnicodeChar = lines[i][j];
            sprite[i * spriteWidth + j].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }
    }

    name = "Move Speed Upgrade";
}

void MoveSpeedUpgrade::ApplyUpgrade() {
    GameManager::Instance()->player->moveSpeed += 0.1f;
}