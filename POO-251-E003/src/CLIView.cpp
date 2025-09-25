
#include "editor/CLIView.h"
#include <iostream>

void CLIView::render(const std::string& content) {
    std::cout << "\n--- RENDERIZACAO DO CANVAS ---\n";
    std::cout << content;
    std::cout << "\n--- FIM DA RENDERIZACAO ---\n";
}

void CLIView::showMessage(const std::string& message) {
    std::cout << "[INFO]: " << message << std::endl;
}