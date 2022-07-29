cmake_minimum_required(VERSION 3.5)

project(Caro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Caro main.cpp model.cpp user.cpp view.cpp control.cpp graphics.cpp exception.cpp)
