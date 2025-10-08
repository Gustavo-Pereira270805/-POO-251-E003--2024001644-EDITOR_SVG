#pragma once

#include <QMainWindow> //classe base do QT
#include "editor/CanvasWidget.h"
#include "editor/Canvas.h"
#include "editor/EditorController.h"
class QAction;
class QMenu;

/**
 * @class MainWindow
 * @brief A janela principal da nossa aplicação de editor SVG.
 *
 * Herda de QMainWindow para fornecer a estrutura padrão de uma aplicação
 * (barra de menus, área central, etc.).
 */
 class MainWindow : public QMainWindow
 {  //macro obrigatória das classes "sinais e slots" do QT
    Q_OBJECT 

public:
    explicit MainWindow(Canvas& canvasModel,EditorController& editorController, QWidget *parent = nullptr);

private slots:
    void saveFile();
    void importFile();

private:


    void createActions();
    void createMenus();

    EditorController& controller;
    QMenu *editMenu;
    QAction *newPolygonAct;
    QMenu *fileMenu;
    QAction *saveAct;
    QAction *exitAct;
    QAction *importAct;
    CanvasWidget *canvasWidget;
 };
