cmake_minimum_required(VERSION 3.13)
project(chunk_pool)

set(CMAKE_CXX_STANDARD 17)

add_library(chunk_pool chunk_pool.cpp chunk_pool.h)