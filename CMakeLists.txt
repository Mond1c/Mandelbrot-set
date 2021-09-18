cmake_minimum_required(VERSION 3.17)
project(Mandelbrot_set)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mandelbrot_set main.cpp)

find_package(SDL2 REQUIRED SDL2)

target_link_libraries(Mandelbrot_set PRIVATE SDL2::SDL2)