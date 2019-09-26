cmake_minimum_required(VERSION 3.15)
project(Farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Farm main.cpp Animal.cpp Farm.cpp Farm.h)