#pragma once

#include <QMainWindow> //classe base do QT

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
    explicit MainWindow(QWidget *parent = nullptr);

private: 
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QAction *saveAct;
    QAction *exitAct;
 }