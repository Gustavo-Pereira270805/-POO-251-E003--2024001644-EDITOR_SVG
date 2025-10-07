cmake_minimum_required(VERSION 3.10)

project(POO-251-E003 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilita funcionalidades automáticas do Qt para o CMake
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Encontra o Qt6 no seu sistema e importa o módulo "Widgets"
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Agrupa todos os arquivos de cabeçalho em uma variável
set(HEADER_FILES
    include/editor/Canvas.h
    include/editor/CLIView.h
    include/editor/EditorController.h
    include/editor/MainWindow.h
    include/editor/Point.h
    include/editor/Polygon.h
    include/editor/Shape.h
    include/editor/View.h
)

# Agrupa todos os arquivos de implementação em outra variável
set(SOURCE_FILES
    src/main.cpp
    src/Point.cpp
    src/Polygon.cpp
    src/Canvas.cpp
    src/CLIView.cpp
    src/EditorController.cpp
    src/MainWindow.cpp
)

# Cria o executável usando as variáveis com todos os arquivos
add_executable(svg_editor_app ${HEADER_FILES} ${SOURCE_FILES})

# "Linka" nosso programa com as bibliotecas do Qt
target_link_libraries(svg_editor_app PRIVATE Qt6::Widgets)

# Informa onde encontrar nossos cabeçalhos
target_include_directories(svg_editor_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)