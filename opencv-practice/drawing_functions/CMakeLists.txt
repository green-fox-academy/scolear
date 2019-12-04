cmake_minimum_required(VERSION 3.15)
project(drawing_functions)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(drawing_functions main.cpp color_definitions.h)

target_link_libraries( drawing_functions ${OpenCV_LIBS} )