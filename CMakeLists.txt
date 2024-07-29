cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME best403unlocker-gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

project(${PROJECT_NAME} LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES

)

file(GLOB HEADERS

)

file(GLOB UIS

)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIS})

target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Widgets
)