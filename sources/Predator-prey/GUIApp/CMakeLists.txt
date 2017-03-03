#GUIApp

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

qt5_add_resources(qrsrc resources/resources.qrc)

set(CMAKE_AUTOUIC ON)

set(FORMS mainwindow.ui)

include_directories(${CMAKE_SOURCE_DIR}/lib)

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

qt5_wrap_ui(calculator_FORMS_HEADERS ${FORMS})

add_executable(GUIApp ${SOURCE_FILES} ${qrsrc} ${FORMS})


target_link_libraries(GUIApp lib)
target_link_libraries(GUIApp Qt5::Core)
target_link_libraries(GUIApp Qt5::Widgets)