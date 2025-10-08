#include "editor/CanvasWidget.h"
#include "editor/Polygon.h"

#include <QPainter>
#include <QPolygonF>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QGuiApplication>
#include <QCursor>
#include <iostream> // Precisamos saber o que é um Polígono para desenhá-lo

CanvasWidget::CanvasWidget(Canvas& canvasModel,EditorController& editorController, QWidget *parent)
    : QWidget(parent), model(canvasModel), controller(editorController)
{
    // Define um tamanho mínimo para nossa área de desenho
    setMinimumSize(400, 300);
    setMouseTracking(true);
}

void CanvasWidget::enterDrawingMode()
{
    currentState = State::DrawingPolygon;
    newPolygonVertices.clear(); // Limpa a lista de vértices anterior
    setCursor(Qt::CrossCursor); // Muda o cursor para uma cruz
    update(); //limpa a tela
}
void CanvasWidget::finishDrawing()
{
    // Só finaliza se tivermos um polígono válido (pelo menos 3 pontos)
    if (currentState == State::DrawingPolygon && newPolygonVertices.size() >= 3) {
        // Usa o controller para adicionar a nova forma ao modelo de dados principal
        controller.addPolygon(newPolygonVertices);
    }

    // Limpa o estado de desenho
    currentState = State::Idle;
    newPolygonVertices.clear();
    setCursor(Qt::ArrowCursor); // Restaura o cursor padrão
    update(); // Força um redesenho final para mostrar a forma preenchida
}

// Esta função é chamada automaticamente pelo Qt sempre que a tela precisa ser redesenhada
void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto& shape_ptr : model.getShapes()) {
        const Polygon* polygon = dynamic_cast<const Polygon*>(shape_ptr.get());
        if (polygon) {
            QPolygonF qpoly;
            const auto& vertices = polygon->getVertices();
            for (const auto& vertex : vertices) {
                qpoly << QPointF(vertex.x, vertex.y);
            }

            if (polygon->isSelected()) {
                painter.setPen(QPen(Qt::red, 2));
                painter.setBrush(QColor(255, 100, 100, 128));
                painter.drawPolygon(qpoly);

                painter.setPen(QPen(Qt::black, 1));
                painter.setBrush(Qt::white);
                for (const auto& vertex : vertices) {
                    painter.drawEllipse(QPointF(vertex.x, vertex.y), 4, 4);
                }
            } else {
                painter.setPen(Qt::blue);
                painter.setBrush(QColorConstants::Svg::lightblue);
                painter.drawPolygon(qpoly);
            }
        }
    }

    if (currentState == State::DrawingPolygon && !newPolygonVertices.empty()) {
        painter.setPen(QPen(Qt::black, 1, Qt::DashLine));
        QPolygonF qpoly_new;
        for (const auto& vertex : newPolygonVertices) {
            qpoly_new << QPointF(vertex.x, vertex.y);
        }
        painter.drawPolyline(qpoly_new);
    }
}
void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    if (currentState == State::DrawingPolygon) {
        // Se o botão esquerdo foi clicado, adiciona um ponto
        if (event->button() == Qt::LeftButton) {
            QPointF clickPos = event->pos();
            newPolygonVertices.push_back(Point(clickPos.x(), clickPos.y()));
            update(); // Força um redesenho para mostrar a nova linha
        }
        // Se o botão direito foi clicado, finaliza o desenho
        else if (event->button() == Qt::RightButton) {
            finishDrawing();
        }
        return; // Finaliza a função aqui para não executar a lógica de seleção
    }

    if (currentState == State::Idle && event->button() == Qt::LeftButton) {
        QPointF clickPos = event->pos();

        // 1. VERIFICA SE O CLIQUE FOI EM UM VÉRTICE (INÍCIO DO ARRASTO)
        for (auto& shape_ptr : model.getShapes()) {
            if (shape_ptr->isSelected()) {
                Polygon* polygon = dynamic_cast<Polygon*>(shape_ptr.get());
                if (polygon) {
                    for (size_t i = 0; i < polygon->getVertices().size(); ++i) {
                        const auto& vertex = polygon->getVertices()[i];
                        QPointF vertexPos(vertex.x, vertex.y);
                        // Checa se a distância do clique ao vértice é pequena
                        if ((clickPos - vertexPos).manhattanLength() < 10) {
                            currentState = State::DraggingVertex;
                            draggedShape = polygon;
                            draggedVertexIndex = i;
                            setCursor(Qt::ClosedHandCursor);
                            update();
                            return; // Encontrou um vértice para arrastar, encerra a função.
                        }
                    }
                }
            }
        }

        // 2. SE NÃO FOI EM UM VÉRTICE, TENTA SELECIONAR A FORMA INTEIRA
        bool shiftIsPressed = QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier);
        bool somethingWasHit = false;

        // Itera de trás para frente para selecionar a forma que está no topo
        for (int i = model.getShapes().size() - 1; i >= 0; --i) {
            auto& shape_ptr = model.getShapes()[i];
            const Polygon* polygon = dynamic_cast<const Polygon*>(shape_ptr.get());

            if (polygon) {
                QPolygonF qpoly;
                for (const auto& vertex : polygon->getVertices()) {
                    qpoly << QPointF(vertex.x, vertex.y);
                }

                if (!somethingWasHit && qpoly.boundingRect().contains(clickPos)) {
                    somethingWasHit = true;
                    if (shiftIsPressed) {
                        // Com Shift, inverte o estado de seleção da forma clicada
                        shape_ptr->setSelected(!shape_ptr->isSelected());
                    } else {
                        // Sem Shift, se a forma já não estiver selecionada,
                        // limpa todas as outras e seleciona apenas esta.
                        if (!shape_ptr->isSelected()) {
                            for (auto& other_shape_ptr : model.getShapes()) {
                                other_shape_ptr->setSelected(false);
                            }
                            shape_ptr->setSelected(true);
                        }
                    }
                }
            }
        }

        // 3. SE CLICOU NO VAZIO (sem Shift), limpa todas as seleções
        if (!somethingWasHit && !shiftIsPressed) {
            for (auto& shape_ptr : model.getShapes()) {
                shape_ptr->setSelected(false);
            }
        }

        update(); // Força o redesenho para mostrar as mudanças na seleção
    }
}
void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (currentState == State::DraggingVertex && draggedShape) {
        QPointF mousePos = event->pos();
        draggedShape->moveVertex(draggedVertexIndex, Point(mousePos.x(), mousePos.y()));
        update();
    }
}
void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && currentState == State::DraggingVertex) {
        currentState = State::Idle;
        draggedShape = nullptr;
        draggedVertexIndex = -1;
        setCursor(Qt::ArrowCursor);
        update();
    }
}
