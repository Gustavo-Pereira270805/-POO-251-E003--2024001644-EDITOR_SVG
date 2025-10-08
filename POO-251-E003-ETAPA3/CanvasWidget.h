#pragma once

#include <QWidget>
#include <vector>
#include "editor/Canvas.h"
#include "editor/Point.h"
#include "editor/EditorController.h"
#include "editor/Polygon.h"
/**
 * @class CanvasWidget
 * @brief O widget customizado que renderiza as formas do nosso modelo Canvas.
 */
class CanvasWidget : public QWidget{
    Q_OBJECT

public:
    //pega uma referencia do modelo de dados
    explicit CanvasWidget(Canvas& canvasModel,EditorController& editorController, QWidget *parent = nullptr);
public slots: // Slots podem ser chamados por outros objetos
    void enterDrawingMode();
private slots:
    void finishDrawing();
protected:
    //sobrescrevemos a função de desenho do QWidget
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    EditorController& controller;
    enum class State { Idle, DrawingPolygon, DraggingVertex }; //3 modos
    State currentState = State::Idle;          // O estado atual
    // Variáveis para guardar qual vértice está sendo arrastado
    Polygon* draggedShape = nullptr;
    int draggedVertexIndex = -1;

    std::vector<Point> newPolygonVertices; //vertices do poligono em criação

    Canvas& model;
};
