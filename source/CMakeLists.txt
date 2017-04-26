cmake_minimum_required (VERSION 2.6)
project (memo)

include_directories(.)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall " )

set(SOURCES main.cpp command_parser.cpp server.cpp)

add_executable(memo ${SOURCES})
target_link_libraries(memo pthread)

