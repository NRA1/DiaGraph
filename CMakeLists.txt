cmake_minimum_required(VERSION 3.18.5)
project(DiaGraph VERSION 0.0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(DiaGraph main.cpp MainWindow.h MainWindow.cpp MainGraphicsView.h MainGraphicsScene.h MainGraphicsShape.cpp MainGraphicsShape.h MainGraphicsHandles.cpp MainGraphicsHandles.h MainGraphicsRectHandle.cpp MainGraphicsRectHandle.h MainGraphicsScene.cpp MainGraphicsView.cpp)

target_link_libraries(DiaGraph Qt5::Widgets)
