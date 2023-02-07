cmake_minimum_required(VERSION 3.22)
project(rgr_csc)

add_executable(test testMatrix.cpp)

set_compile_options(test)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/gtest)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/libcsc)

target_link_libraries(test PRIVATE matrix )
target_link_libraries(test PRIVATE gtest gtest_main)

add_custom_target(check ALL COMMAND test)

