// src/main.cpp

#include "editor/Canvas.h"
#include "editor/CLIView.h"
#include "editor/EditorController.h"
#include "editor/Point.h"
#include "editor/Polygon.h"
#include <vector>

int main() {
    // 1. Criar os componentes principais da arquitetura MVC
    Canvas canvas; // O Modelo
    CLIView view;   // A Visão
    EditorController controller(canvas, view); // O Controlador (conectando Modelo e Visão)

    // 2. Simular ações do usuário usando o Controlador
    view.showMessage("Criando um triangulo...");
    std::vector<Point> triangleVertices = { Point(150, 50), Point(50, 250), Point(250, 250) };
    controller.addPolygon(triangleVertices);

    view.showMessage("Criando um retangulo...");
    std::vector<Point> rectangleVertices = { Point(300, 100), Point(500, 100), Point(500, 200), Point(300, 200) };
    controller.addPolygon(rectangleVertices);

    // 3. Renderizar o estado atual do canvas na View (nosso terminal)
    controller.renderCurrentCanvas();

    // 4. Salvar o resultado em um arquivo SVG, como pedido na Etapa 2 [cite: 111]
    controller.saveCanvasToFile("output.svg");

    return 0;
}