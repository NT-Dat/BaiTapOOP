cmake_minimum_required(VERSION 3.5)

project(Bai1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai1 main.cpp officer.cpp worker.cpp engineer.cpp staff.cpp managerofficer.cpp)
