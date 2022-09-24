#ifndef CONSOLESURVIVOR_UPGRADE_H
#define CONSOLESURVIVOR_UPGRADE_H

#include <windows.h>
#include <stdio.h>
#include <string>

class Upgrade {
public:
    int spriteWidth;
    int spriteHeight;
    std::string name;
    CHAR_INFO* sprite;
    int level = 0;
    virtual void ApplyUpgrade() = 0;
};


#endif //CONSOLESURVIVOR_UPGRADE_H
