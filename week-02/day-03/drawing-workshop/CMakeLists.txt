cmake_minimum_required(VERSION 3.14)
project(drawing_setup)

set(CMAKE_CXX_STANDARD 14)


set(SDL2_ROOT_PATH /usr/lib)

set(EXECUTABLES "draw;coloredbox;middleLines;diagonals;goToCenter;horizontals;centeredSquare;fourRect;utils;positionSquare;centerBoxFunction;rainbowBox;purpleSteps;purpleSteps3D;checkerboard;functionToCenter;connectDots;starryNight;blinkingSquare")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

IF(WIN32)
    set(MINGW_VERSION i686-w64-mingw32)
ENDIF()

find_package(SDL2_all REQUIRED)
