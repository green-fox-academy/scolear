cmake_minimum_required(VERSION 3.15)
project(opencv_practice)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(opencv_practice main.cpp saturation.cpp saturation.h)

target_link_libraries( opencv_practice ${OpenCV_LIBS} )