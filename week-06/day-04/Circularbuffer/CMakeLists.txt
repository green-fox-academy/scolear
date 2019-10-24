cmake_minimum_required(VERSION 3.15)
project(Circularbuffer C)

set(CMAKE_C_STANDARD 99)

add_executable(Circularbuffer main.c circbuff.h circbuff.c)