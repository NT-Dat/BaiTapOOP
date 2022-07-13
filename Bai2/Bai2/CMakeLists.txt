cmake_minimum_required(VERSION 3.5)

project(Bai2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai2 main.cpp document.cpp book.cpp journal.cpp newspaper.cpp managerdocument.cpp)
