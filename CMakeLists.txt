cmake_minimum_required(VERSION 3.23)
project(ConsoleSurvivor)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleSurvivor "src/main.cpp" "src/ConsoleSurvivorGame.cpp" "src/NYTimer.cpp" src/InputHandler.cpp src/InputHandler.h src/Vector2.cpp src/Vector2.h src/Renderer.cpp src/Renderer.h)

