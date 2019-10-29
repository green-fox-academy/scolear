cmake_minimum_required(VERSION 3.15)
project(genericvector C)

set(CMAKE_C_STANDARD 99)

add_executable(genericvector main.c genvector.c genvector.h)