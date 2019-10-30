cmake_minimum_required(VERSION 3.15)
project(linkedlist C)

set(CMAKE_C_STANDARD 99)

add_executable(linkedlist main.c linkedlist.c linkedlist.h)