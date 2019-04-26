cmake_minimum_required(VERSION 3.13)
project(fc_new)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory( fc )

add_executable(fc_new main.cpp)

target_link_libraries (fc_new fc)