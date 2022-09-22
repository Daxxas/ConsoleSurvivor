cmake_minimum_required(VERSION 3.23)
project(ConsoleSurvivor)
add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleSurvivor "src/main.cpp" "src/ConsoleSurvivorGame.cpp" "src/NYTimer.cpp" "src/InputHandler.cpp" "src/Vector2.cpp" "src/Renderer.cpp" "src/Entities/Entity.cpp" "src/Entities/Player.cpp" "src/GameManager.cpp" "src/Entities/BatEnemy.cpp" "src/Entities/Bullet.cpp" "src/Entities/Creature.cpp" src/Pool.cpp src/Pool.h)


