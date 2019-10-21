cmake_minimum_required(VERSION 3.15)
project(pi C)

set(CMAKE_C_STANDARD 99)

add_executable(pi main.c circle.h circle.c)