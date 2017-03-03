#UnitTests

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(ModelTest tst_modeltest.cpp)
target_link_libraries(ModelTest Qt5::Core)
target_link_libraries(ModelTest Qt5::Test)
target_link_libraries(ModelTest lib)