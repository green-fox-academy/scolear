cmake_minimum_required(VERSION 3.15)
project(InstrumentstoStringedInstruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(InstrumentstoStringedInstruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h BassGuitar.cpp BassGuitar.h Violin.cpp Violin.h)