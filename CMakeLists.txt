cmake_minimum_required(VERSION 3.2)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Example.hpp
)

set(Sources
    main.cpp
)

add_library(${This} SHARED ${Sources} ${Headers})

add_subdirectory(test)
