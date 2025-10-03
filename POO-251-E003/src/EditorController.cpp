// src/EditorController.cpp

#include "editor/EditorController.h"
#include "editor/Polygon.h" 
#include <memory>           
#include <fstream>       // Para salvar arquivos 


EditorController::EditorController(Canvas& canvas, View& view)
    : model(canvas), view(view) {
}

void EditorController::addPolygon(const std::vector<Point>& vertices) {
    auto polygon = std::make_unique<Polygon>(vertices);

    model.addShape(std::move(polygon));

    view.showMessage("Poligono adicionado ao canvas.");
}

void EditorController::renderCurrentCanvas() {
   std::string svgContent = model.toSVGFileString();

    view.render(svgContent);
}

void EditorController::saveCanvasToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << model.toSVGFileString(); 
        outFile.close();
        view.showMessage("Canvas salvo com sucesso em: " + filename);
    } else {
        view.showMessage("ERRO: Nao foi possivel abrir o arquivo para escrita.");
    }
}