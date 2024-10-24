cmake_minimum_required(VERSION 3.16)

project(best403unlocker-qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp
     ${CMAKE_SOURCE_DIR}/ui/*.ui)

add_executable(best403unlocker-qt ${SOURCES} assets/resources.qrc)

target_link_libraries(best403unlocker-qt PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                                 Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS best403unlocker-qt RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
