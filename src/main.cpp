#include <iostream>
#include <windows.h>

#include "idConsoleSurvivorGame.h"

using namespace std;

int main() {
    idConsoleSurvivorGame game = idConsoleSurvivorGame();
    game.launchGame();
    return 0;
}