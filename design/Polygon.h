#pragma once

#include "Shape.h"
#include "Point.h"

#include <vector> // para guardar a lista de vertices

/**
 * @class Polygon
 * @brief Representa uma forma poligonal concreta.
 *
 * Esta classe herda da classe abstrata Shape e implementa seus
 * métodos virtuais puros. Um polígono é composto por uma lista de vértices.
 */
class Polygon : public Shape {
    public:
        explicit Polygon(const std::vector<Point>& initialVertices);

        void move(const Point& offset) override;

        std::string toSVGstring() const override;

        /** @brief Adiciona um novo vértice ao final do polígono. */
        void addVertex(const Point& vertex);

        /** @brief Retorna uma referência constante para a lista de vértices. */
        const std::vector<Point>& getVertices() const;
}