cmake_minimum_required(VERSION 3.5)

project(Caro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Caro main.cpp _common.cpp _point.cpp _board.cpp player.cpp _game.cpp)
