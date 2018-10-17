cmake_minimum_required (VERSION 3.0)

project (Homework_Hello_World)

set(HEADER_FILES point.h sphere.h)
add_library(sphere sphere.cpp ${HEADER_FILES}) 
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(main sphere)

include(gtest.cmake)
add_executable(tests unit_tests.cpp)
find_package (Threads)
target_link_libraries(tests sphere gtest ${CMAKE_THREAD_LIBS_INIT})
target_compile_options(tests PRIVATE -std=c++0x -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
