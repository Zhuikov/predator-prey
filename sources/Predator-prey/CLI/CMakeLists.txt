#CLI

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(
        CLI_SOURCE_FILES

        cli.cpp cli.h
        logging.cpp logging.h
        main.cpp
)

add_executable(CLI ${CLI_SOURCE_FILES})

target_link_libraries(CLI lib)