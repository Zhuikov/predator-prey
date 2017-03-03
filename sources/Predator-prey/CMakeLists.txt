cmake_minimum_required(VERSION 3.5)
project(Predator_prey)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11")

add_subdirectory(consoleApp)
add_subdirectory(lib)
add_subdirectory(CLI)
add_subdirectory(GUIApp)
add_subdirectory(tests)