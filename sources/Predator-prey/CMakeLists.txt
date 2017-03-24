cmake_minimum_required(VERSION 3.0.2)
project(Predator_prey)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -static-libgcc -static-libstdc++")

add_subdirectory(consoleApp)
add_subdirectory(lib)
add_subdirectory(CLI)
add_subdirectory(GUIApp)
add_subdirectory(tests)