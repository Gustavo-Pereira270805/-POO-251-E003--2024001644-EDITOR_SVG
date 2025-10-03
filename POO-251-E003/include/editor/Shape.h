#pragma once

#include <string>
#include "Point.h"

/**
 * @class Shape
 * @brief Classe base abstrata para todas as formas geométricas.
 */
class Shape {
public:

    virtual ~Shape() = default;

    /**
     * @brief Move a forma por um determinado deslocamento.
     * @param offset O vetor (representado por um Point) de deslocamento.
     */
    virtual void move(const Point& offset) = 0;

    /**
     * @brief Gera a representação da forma em formato de string SVG.
     * @return Uma string contendo a tag SVG para esta forma.
     */
    virtual std::string toSVGString() const = 0;
};