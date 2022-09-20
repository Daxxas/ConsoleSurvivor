#include <windows.h>
#include <iostream>

#include "NYTimer.h"
#include "Vector2.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "ConsoleSurvivorGame.h"
#include "GameManager.h"
#include "Renderer.h"

using namespace std;

int main() {
    ConsoleSurvivorGame game = ConsoleSurvivorGame();
    game.launchGame();
    return 0;
}