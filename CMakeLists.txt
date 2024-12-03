cmake_minimum_required(VERSION 3.16)

project(ShiftManagerPlusPlus VERSION 0.1 LANGUAGES CXX)

# Enable automatic Qt features
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Include the directory for headers and UI files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# Add sources, headers, and UI files
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/dbhandler.cpp
    src/shift.cpp
)

set(HEADERS
    include/mainwindow.h
    include/dbhandler.h
    include/shift.h
)

set(UI_FILES
    ui/mainwindow.ui
)

# Add executable
qt_add_executable(ShiftManagerPlusPlus
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# Link libraries
target_link_libraries(ShiftManagerPlusPlus PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
