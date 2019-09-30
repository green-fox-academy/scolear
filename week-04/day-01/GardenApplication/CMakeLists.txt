cmake_minimum_required(VERSION 3.15)
project(GardenApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(GardenApplication main.cpp Garden.cpp Garden.h Plant.cpp Plant.h Flower.cpp Flower.h Tree.cpp Tree.h)