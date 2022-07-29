cmake_minimum_required(VERSION 3.5)

project(Bai13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai13 main.cpp Certificate.cpp Employee.cpp Experience.cpp Fresher.cpp Intern.cpp ManagerEmployee.cpp Certificate.h Employee.h Experience.h Fresher.h Intern.h ManagerEmployee.h)
