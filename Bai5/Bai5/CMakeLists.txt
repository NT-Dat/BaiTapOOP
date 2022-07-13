cmake_minimum_required(VERSION 3.5)

project(Bai5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai5 main.cpp person.cpp hotel.cpp room.cpp)
