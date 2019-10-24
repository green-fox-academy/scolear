cmake_minimum_required(VERSION 3.15)
project(Points C)

set(CMAKE_C_STANDARD 99)

add_executable(Points main.c)

target_link_libraries(Points m)