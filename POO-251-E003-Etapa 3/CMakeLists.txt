cmake_minimum_required(VERSION 3.10)

project(POO-251-E003 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilita funcionalidades automáticas do Qt para o CMake
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 COMPONENTS Widgets Xml REQUIRED)


set(HEADER_FILES
    include/editor/Canvas.h
    include/editor/CanvasWidget.h
    include/editor/CLIView.h
    include/editor/EditorController.h
    include/editor/MainWindow.h
    include/editor/Point.h
    include/editor/Polygon.h
    include/editor/Shape.h
    include/editor/View.h
)


set(SOURCE_FILES
    src/main.cpp
    src/Point.cpp
    src/Polygon.cpp
    src/Canvas.cpp
    src/CanvasWidget.cpp
    src/CLIView.cpp
    src/EditorController.cpp
    src/MainWindow.cpp
)


add_executable(svg_editor_app ${HEADER_FILES} ${SOURCE_FILES}
    include/editor/CanvasWidget.h
    src/CanvasWidget.cpp)

# "Linka" nosso programa com as bibliotecas do Qt
target_link_libraries(svg_editor_app PRIVATE Qt6::Widgets Qt6::Xml)

# Informa onde encontrar nossos cabeçalhos
target_include_directories(svg_editor_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
