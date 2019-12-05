cmake_minimum_required(VERSION 3.15)
project(find_contours)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(find_contours main.cpp)

target_link_libraries(find_contours ${OpenCV_LIBS} )