cmake_minimum_required(VERSION 3.15)
project(asciigen C)

set(CMAKE_C_STANDARD 99)

add_executable(asciigen main.c asciigen.c asciigen.h)