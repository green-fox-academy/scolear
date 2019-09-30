cmake_minimum_required(VERSION 3.15)
project(greenFox)

set(CMAKE_CXX_STANDARD 14)

add_executable(greenFox main.cpp Person.cpp Person.h Student.cpp Student.h Mentor.cpp Mentor.h Sponsor.cpp Sponsor.h Cohort.cpp Cohort.h)