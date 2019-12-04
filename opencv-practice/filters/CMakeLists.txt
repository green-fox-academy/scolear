cmake_minimum_required(VERSION 3.15)
project(filters)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(filters main.cpp)

target_link_libraries(filters ${OpenCV_LIBS})