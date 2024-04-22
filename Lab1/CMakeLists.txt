cmake_minimum_required(VERSION 3.17)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab1
        Bag.cpp
        Bag.hpp
        BagIterator.cpp
        BagIterator.hpp
        main.cpp
        ShortTest.cpp
        ShortTest.hpp)
