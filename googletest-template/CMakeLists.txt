cmake_minimum_required(VERSION 3.20)
project(google-test-exercise)

add_subdirectory(lib)

include(CTest)
add_subdirectory(test)

