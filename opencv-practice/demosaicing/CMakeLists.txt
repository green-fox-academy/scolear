cmake_minimum_required(VERSION 3.15)
project(demosaicing)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(demosaicing main.cpp demosaicing.cpp demosaicing.h)
target_link_libraries(demosaicing ${OpenCV_LIBS} )