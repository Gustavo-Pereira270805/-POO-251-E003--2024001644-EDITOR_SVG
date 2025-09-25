#pragma once

#include "Shape.h"
#include <vector>
#include <memory> // Essencial para smart pointers como std::unique_ptr/**
/**
 * @class Canvas
 * @brief Representa a tela de desenho que contém e gerencia todas as formas.
 *
*/
class Canvas {
    public:
        Canvas();
    /**
     * @brief Adiciona uma nova forma ao Canvas.
     * @param shape Um ponteiro único para a forma. A posse da forma é
     * transferida para o Canvas.
     */
        void addShape(std::unique_ptr<Shape> shape);
    /**
     * @brief Gera o conteúdo completo do arquivo SVG, incluindo todas as formas.
     */
        std::string toSVGFilestring() const;

    /** @brief Retorna uma referência constante para a lista de formas. */
        const std::vector<std::unique_ptr<Shape>>& getShapes() const;

    private:
        std::vector<std::unique_ptr<Shape>> shapes;
};