#include "editor/Polygon.h"
#include <sstream> // Para construir a string SVG eficientemente
#include <iomanip> // Para formatação de ponto flutuante

Polygon::Polygon(const std::vector<Point>& initialVertices) : 
    vertices(initialVertices) {}

void Polygon::move(const Point& offset) {
    for (Point& vertex : vertices) {
        vertex = vertex + offset;
        }
    }

std::string Polygon::toSVGString() const {
    if (vertices.size()< 2) {
        return ""; //polígono tem no minimo 2 vértices
    }

std::stringstream ss;
ss << std::fixed << std::setprecision(2);
ss << "<polygon points=\"";
for(size_t i = 0; i < vertices.size(); i++) {
    ss << vertices[i].x << "," << vertices[i].y;
    if (i < vertices.size() - 1) {
        ss << " ";
    }
}
ss << "\" fill=\"lightblue\" stroke=\"blue\" />";
return ss.str();
}

void Polygon::addVertex(const Point& vertex) {
    vertices.push_back(vertex);
}

const std::vector<Point>& Polygon::getVertices() const {
    return vertices;
}