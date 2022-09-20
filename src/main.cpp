#include <windows.h>
#include <iostream>

#include "Vector2.h"
#include "NYTimer.h"
#include "InputHandler.h"
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