// src/main.cpp

#include "editor/Canvas.h"
#include "editor/CLIView.h"
#include "editor/EditorController.h"
#include "editor/Point.h"
#include "editor/Polygon.h"
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>
void showHelp() {
    std::cout << "--- Editor SVG (Modo CLI) ---\n"
              << "Comandos disponiveis:\n"
              << "  add polygon x1,y1 x2,y2 ...  - Adiciona um poligono com os vertices fornecidos\n"
              << "  render                       - Renderiza o estado atual do canvas no terminal\n"
              << "  save <nome_do_arquivo.svg>   - Salva o canvas em um arquivo SVG\n"
              << "  help                         - Mostra esta mensagem de ajuda\n"
              << "  exit                         - Fecha o programa\n"
              << "---------------------------------\n";
}

int main() {
    // 1. Criar os componentes principais da arquitetura MVC
    Canvas canvas; // O Modelo
    CLIView view;   // A Visão
    EditorController controller(canvas, view); // O Controlador (conectando Modelo e Visão)

    showHelp();
    std::string inputLine;
    while (true) {
       std::cout << "> "; 
        if (!std::getline(std::cin, inputLine)) {
            break; // Sai do loop se houver erro na entrada (ex: fim de arquivo)
        }
        std::stringstream ss(inputLine);
        std::string command;
        ss >> command;

        if (command == "exit"){
            view.showMessage("Saindo do editor...");
            break; // Quebra o loop e encerra o programa
        } else if (command == "help") {
            showHelp();
        }else if (command == "render") {
            controller.renderCurrentCanvas();
        } else if (command == "save") {
            std::string fileName;
            ss >> fileName;
            if (fileName.empty()) {
                view.showMessage("Você deve fornecer um nome de arquivo.");
            }else {
                controller.saveCanvasToFile(fileName);
            }
        } else if (command == "add") {
            std::string subCommand;
            ss >> subCommand;
            if(subCommand == "polygon"){
                std::vector<Point> vertices;
                std::string coordPairStr;
                bool error = false;
                while (ss>>coordPairStr) {
                    try {
                        std::stringstream coord_ss(coordPairStr);
                        std::string xStr, yStr;
                        if (!std::getline(coord_ss, xStr, ',')) throw std::invalid_argument("Formato inválido");
                        if (!std::getline(coord_ss, yStr)) throw std::invalid_argument("Falta a coordenada Y");
                    double x = std::stod(xStr);
                    double y = std::stod(yStr);
                    vertices.push_back(Point(x, y));
                } catch (const std::exception& e) {
                    view.showMessage("Erro ao ler o par de coordenadas: '" + coordPairStr + "'. Erro: " + e.what());
                    error = true;
                    break;
                }
            }
            if(!error && vertices.size()>=3){
                controller.addPolygon(vertices);
            }else if (!error){
                view.showMessage("Você deve fornecer pelo menos 3 coordenadas.");
            }
        } else {
            view.showMessage("Comando desconhecido. Você quis dizer 'add polygon'?");
        }
    }else if (command.empty()) {
            // Se o usuário apenas apertar Enter, não faz nada
            continue;
        }
        else {
            view.showMessage("Comando desconhecido. Digite 'help' para ver as opcoes.");
        }
    }

    return 0;
}