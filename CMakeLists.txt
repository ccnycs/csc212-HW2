cmake_minimum_required (VERSION 3.0)

project (Homework_Hello_World)

set(HEADER_FILES point.h sphere.h)
add_library(sphere sphere.cpp ${HEADER_FILES}) 
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(main sphere)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

add_executable(tests unit_tests.cpp)
find_package (Threads)
target_link_libraries(tests sphere gtest ${CMAKE_THREAD_LIBS_INIT})
target_compile_options(tests PRIVATE -std=c++0x -g -Wall)
