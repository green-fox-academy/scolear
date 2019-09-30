cmake_minimum_required(VERSION 3.15)
project(AircraftCarrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(AircraftCarrier main.cpp Aircraft.cpp Aircraft.h F16.cpp F16.h F35.cpp F35.h Carrier.cpp Carrier.h)