cmake_minimum_required(VERSION 3.5)

project(Bai13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Bai13 main.cpp employee.cpp experience.cpp fresher.cpp intern.cpp certificate.cpp employeemanagement.cpp)
