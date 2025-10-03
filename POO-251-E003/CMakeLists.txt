cmake_minimum_required(VERSION 3.10)

project(POO-251-E003 Languages CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(svg_editor_app
    src/main.cpp
    src/Point.cpp
    src/Polygon.cpp
    src/Canvas.cpp
    src/CLIView.cpp
    src/EditorController.cpp
)


target_include_directories(svg_editor_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
