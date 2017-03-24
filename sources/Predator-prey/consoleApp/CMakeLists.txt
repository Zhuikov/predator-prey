#consoleApp

include_directories(${CMAKE_SOURCE_DIR}/lib)

set(
        CONSOLE_APP_SOURCE_FILES

        badinput.h
        consoleapp.cpp consoleapp.h
        consoledialog.cpp consoledialog.h
        consoledrawer.cpp consoledrawer.h
        main.cpp
)

add_executable(CONSOLE_APP ${CONSOLE_APP_SOURCE_FILES})

target_link_libraries(CONSOLE_APP lib)