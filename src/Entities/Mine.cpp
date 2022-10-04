#include "Mine.h"

Mine::Mine(Shooter* shooter, Vector2& position, Vector2& direction, int damage, float speed) : Bullet(shooter, position, direction, damage, speed) {
    spriteWidth = 1;
    spriteHeight = 1;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    sprite[0].Char.UnicodeChar = 'x';
    sprite[0].Attributes = 0x0006;
}