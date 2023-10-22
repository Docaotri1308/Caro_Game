cmake_minimum_required(VERSION 3.16)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe src/main.cpp
        include/board.h
        src/board.cpp
        include/player.h
        src/player.cpp)