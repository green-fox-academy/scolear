cmake_minimum_required(VERSION 3.15)
project(Shop_statistics C)

set(CMAKE_C_STANDARD 99)

add_executable(Shop_statistics main.c hourlies.c hourlies.h)