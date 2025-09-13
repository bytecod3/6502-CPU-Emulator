cmake_minimum_required(VERSION 3.5)
project(6502-CPU-Emulator)

add_executable(
        main
        src/main.c
        src/cpu.c
        src/memory-map.c
)

target_include_directories(
        main PUBLIC
        "$(CMAKE_CURRENT_SOURCE_DIR}/include"
)

