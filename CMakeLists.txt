cmake_minimum_required(VERSION 3.3)
project(5sem_baza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES labs/sem3.cpp)
add_executable(5sem_baza ${SOURCE_FILES})