cmake_minimum_required(VERSION 3.16)
project(Caro_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Caro_Game src/main.cpp
        include/board.h
        src/board.cpp
        include/player.h
        src/player.cpp)