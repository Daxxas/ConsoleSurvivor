cmake_minimum_required(VERSION 3.23)
project(ConsoleSurvivor)
add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleSurvivor "src/main.cpp" "src/ConsoleSurvivorGame.cpp" "src/NYTimer.cpp" "src/InputHandler.cpp" "src/Vector2.cpp" "src/Renderer.cpp" "src/Entities/Entity.cpp" "src/Entities/Player.cpp" "src/GameManager.cpp" "src/Entities/BatEnemy.cpp" "src/Entities/Bullet.cpp" "src/Entities/Creature.cpp" "src/Upgrades/MoveSpeedUpgrade.cpp" "src/Upgrades/UpgradeList.cpp" "src/Upgrades/AttackSpeedUpgrade.cpp" "src/CreatureSpawners/CreatureSpawner.cpp" "src/CreatureSpawners/BatSpawner.cpp" "src/CreatureSpawners/UwUSpawner.cpp" "src/Entities/UwUEnemy.cpp" "src/Entities/UwUEnemy.h" "src/Upgrades/Upgrade.cpp" "src/Upgrades/Upgrade.h" "src/Upgrades/MoveSpeedUpgrade.cpp" "src/Upgrades/MoveSpeedUpgrade.h" "src/Upgrades/UpgradeList.cpp" "src/Upgrades/UpgradeList.h" "src/Upgrades/AttackSpeedUpgrade.cpp" "src/Upgrades/AttackSpeedUpgrade.h" "src/Shooters/Shooter.cpp" "src/Shooters/Shooter.h" "src/Shooters/BasicShooter.cpp" "src/Shooters/BasicShooter.h" "src/Shooters/HorizontalShooter.cpp" "src/Shooters/HorizontalShooter.h" "src/Upgrades/HorizontalUpgrade.cpp" "src/Upgrades/HorizontalUpgrade.h" "src/Shooters/VerticalShooter.cpp" "src/Shooters/VerticalShooter.h" "src/Upgrades/VerticalUpgrade.cpp" "src/Upgrades/VerticalUpgrade.h" "src/Entities/Mine.cpp" "src/Entities/Mine.h" "src/Shooters/MineShooter.cpp" "src/Shooters/MineShooter.h" "src/Upgrades/MineUpgrade.cpp" "src/Upgrades/MineUpgrade.h")



