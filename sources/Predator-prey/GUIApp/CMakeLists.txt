#GUIApp

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(FORMS mainwindow.ui)
set(QRSRC resources/resources.qrc)

set(
        SOURCE_FILES

        exitwindow.cpp exitwindow.h
        fieldframe.cpp fieldframe.h
        main.cpp
        mainmenu.cpp mainmenu.h
        modelgui.cpp modelgui.h
        modelwindow.cpp modelwindow.h
        resultwindow.cpp resultwindow.h
        seedwindow.cpp seedwindow.h
        settingswindow.cpp settingswindow.h
        statusframe.cpp statusframe.h
)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(GUIApp ${SOURCE_FILES} ${QRSRC} ${FORMS})


target_link_libraries(GUIApp lib)
target_link_libraries(GUIApp Qt5::Core)
target_link_libraries(GUIApp Qt5::Widgets)