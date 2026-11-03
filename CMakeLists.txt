cmake_minimum_required(VERSION 3.10)
project(DynamicArrayPart5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

include_directories(include)

add_executable(main src/main.cpp)
