
#include "BatEnemy.h"

BatEnemy::BatEnemy(Vector2& position) : Entity(position) {
    spriteWidth = 3;
    spriteHeight = 1;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    memset(sprite, 0, sizeof(CHAR_INFO) * spriteWidth * spriteHeight);
    sprite[0].Char.AsciiChar = '>';
    sprite[1].Char.AsciiChar = 'o';
    sprite[2].Char.AsciiChar = '<';

    sprite[0].Attributes = 0x0006;
    sprite[1].Attributes = 0x0006;
    sprite[2].Attributes = 0x0006;

}

void BatEnemy::Update() {

}

CHAR_INFO *BatEnemy::Display() {
    return sprite;
}