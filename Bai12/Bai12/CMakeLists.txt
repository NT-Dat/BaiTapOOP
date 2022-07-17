cmake_minimum_required(VERSION 3.5)

project(Bai12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai12 main.cpp vehicle.cpp car.cpp motorbike.cpp truck.cpp managervehicle.cpp)
