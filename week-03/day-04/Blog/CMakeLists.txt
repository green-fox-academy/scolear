cmake_minimum_required(VERSION 3.15)
project(Blog)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blog main.cpp BlogPost.cpp Blog.cpp Blog.h)