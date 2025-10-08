
#include "editor/EditorController.h"
#include "editor/Polygon.h"
#include <memory>
#include <fstream>       // Para salvar arquivos
#include <QFile>
#include <QXmlStreamReader>
#include <QString>
#include <QDebug>

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
void EditorController::importSvgFromFile(const std::string& filename)
{
    // Limpa o canvas atual antes de importar um novo arquivo
    model.clearAllShapes();

    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        view.showMessage("Erro: Nao foi possivel abrir o arquivo para leitura.");
        return;
    }

    QXmlStreamReader xml(&file);
    std::vector<Point> vertices;

    // Loop principal que lê o arquivo XML "token" por "token"
    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();
        if (xml.isStartElement() && xml.name().toString() == "polygon") {
            // Encontramos uma tag <polygon>
            vertices.clear();
            QXmlStreamAttributes attributes = xml.attributes();

            if (attributes.hasAttribute("points")) {
                QString pointsStr = attributes.value("points").toString();

                // Processa a string de pontos (ex: "10,20 30,40 ...")
                QStringList pointsList = pointsStr.split(' ', Qt::SkipEmptyParts);
                for (const QString& pointPair : pointsList) {
                    QStringList coords = pointPair.split(',');
                    if (coords.size() == 2) {
                        vertices.push_back(Point(coords[0].toDouble(), coords[1].toDouble()));
                    }
                }
            }

            // Se conseguimos extrair vértices, cria o polígono e o adiciona ao modelo
            if (vertices.size() >= 3) {
                addPolygon(vertices);
            }
        }
    }

    if (xml.hasError()) {
        view.showMessage("Erro ao processar o arquivo SVG: " + xml.errorString().toStdString());
    } else {
        view.showMessage("Arquivo SVG importado com sucesso.");
    }
}
