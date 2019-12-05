cmake_minimum_required(VERSION 3.15)
project(background_substraction)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(background_substraction main.cpp)
target_link_libraries(background_substraction ${OpenCV_LIBS} )