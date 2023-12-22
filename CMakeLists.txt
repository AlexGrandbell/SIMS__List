cmake_minimum_required(VERSION 3.25)
project(SIMS__List)

set(CMAKE_CXX_STANDARD 17)

add_executable(SIMS__List main.cpp tool.cpp tool.h Student.cpp Student.h LinkList.h menu.cpp menu.h Exception.h)
