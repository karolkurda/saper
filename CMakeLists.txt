cmake_minimum_required(VERSION 3.14)
project(saper)

set(CMAKE_CXX_STANDARD 14)

add_executable(saper main.cpp MinesweeperBoard.cpp MinesweeperBoard.h Array2D.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h)
