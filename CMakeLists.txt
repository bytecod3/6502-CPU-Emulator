cmake_minimum_required(VERSION 3.5)
project(6502-CPU-Emulator)

#add all source files
file(GLOB SOURCES src/*.c)

# create an executable
add_executable(main ${SOURCES} )

include_directories(include)

# where to find headers
target_include_directories(main PRIVATE include)

