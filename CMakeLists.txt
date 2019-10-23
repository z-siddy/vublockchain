cmake_minimum_required(VERSION 3.13)
project(vublockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(vublockchain main.cpp headers/hash.h headers/main.h)