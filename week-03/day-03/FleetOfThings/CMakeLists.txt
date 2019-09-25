cmake_minimum_required(VERSION 3.14)
project(FleetOfThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(FleetOfThings main.cpp fleet.cpp thing.cpp)