cmake_minimum_required(VERSION 3.15)
project(AnimalsintheZoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnimalsintheZoo main.cpp Animals.cpp Animals.h Mammal.cpp Mammal.h Reptile.cpp Reptile.h EggLaying.cpp EggLaying.h Bird.cpp Bird.h)