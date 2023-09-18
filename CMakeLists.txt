cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Raft)

if(UNIX)
    message("HELLO WORLD")
endif()

# include_directories(util)
add_executable(raft main.cpp util/timer.cpp util/timer.h)