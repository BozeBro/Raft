# cmake_minimum_required(VERSION 3.27)

# set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(UNIX)
    message("HELLO WORLD")
endif()
# add_executable(Raft main.cpp include/timer.h src/timer.cpp)

file(GLOB SOURCES "*.cpp")

add_executable(RaftProject ${SOURCES})
target_link_libraries(RaftProject src)