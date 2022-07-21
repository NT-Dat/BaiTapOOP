cmake_minimum_required(VERSION 3.5)

project(Bai15 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai15 main.cpp formaluniversitystudent.cpp studentinservice.cpp result.cpp department.cpp manager.cpp)
