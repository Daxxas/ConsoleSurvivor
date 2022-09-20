cmake_minimum_required(VERSION 3.23)
project(ConsoleSurvivor)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleSurvivor "src/main.cpp" "src/ConsoleSurvivorGame.cpp" "src/NYTimer.cpp" "src/InputHandler.cpp" "src/Vector2.cpp" "src/Renderer.cpp" "src/Characters/Entity.cpp" "src/Characters/Player.cpp"  "src/GameManager.cpp")


