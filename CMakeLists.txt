cmake_minimum_required(VERSION 3.16)

project(LockFreeRingBuffer
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ring_buffer_demo
    src/main.cpp
)

target_include_directories(ring_buffer_demo 
    PRIVATE 
        include
)

target_compile_options(ring_buffer_demo 
    PRIVATE 
        -Wall 
        -Wextra 
        -Wpedantic 
        -O3
)