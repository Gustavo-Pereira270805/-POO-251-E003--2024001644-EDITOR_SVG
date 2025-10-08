#include "editor/MainWindow.h"
#include "editor/CanvasWidget.h"
#include "editor/Canvas.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QKeySequence> //para atalhos do teclado

MainWindow::MainWindow(Canvas& canvasModel,EditorController& editorController, QWidget *parent)
    : QMainWindow(parent), controller(editorController) // Chama o construtor da classe pai
{
    createActions();
    createMenus();

    setWindowTitle("Editor SVG - Projeto POO");
    resize(800, 600);


    // Cria nosso widget de desenho, passando o modelo de dados para ele.
    canvasWidget = new CanvasWidget(canvasModel, controller, this);
    // Define o canvasWidget como o widget central da nossa janela principal.
    setCentralWidget(canvasWidget);

    connect(exitAct, &QAction::triggered, this, &QMainWindow::close);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);
    connect(newPolygonAct, &QAction::triggered, canvasWidget, &CanvasWidget::enterDrawingMode);
    connect(importAct, &QAction::triggered, this, &MainWindow::importFile);
}
void MainWindow :: createActions()
{
    //cria a acao de "Salvar"
    saveAct = new QAction("&Salvar", this);
    saveAct -> setShortcuts(QKeySequence::Save);//padrao Ctrl + s

    exitAct = new QAction("&Sair", this);
    exitAct -> setShortcuts(QKeySequence::Quit); //Ctrl + Q

    importAct = new QAction("&Importar SVG...", this);

    newPolygonAct = new QAction("&Novo Poligono", this);
    newPolygonAct->setShortcut(tr("Ctrl+N"));
}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&Arquivo");//adiciona menu de arquivos
    fileMenu->addAction(importAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();//linha de separacao
    fileMenu->addAction(exitAct);
    editMenu = menuBar()->addMenu("&Editar");
    editMenu->addAction(newPolygonAct);

}
void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Salvar Arquivo SVG","",
                                                    "Arquivos SVG (*.svg);;Todos os arquivos (*)");
    if (!fileName.isEmpty()) {
        //(fileName.toStdString() converte o tipo de string do Qt para o std::string)
        controller.saveCanvasToFile(fileName.toStdString());

}
}
#include <QFileDialog>

void MainWindow::importFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Abrir Arquivo SVG", "",
                                                    "Arquivos SVG (*.svg);;Todos os Arquivos (*)");

    if (!fileName.isEmpty()) {
        controller.importSvgFromFile(fileName.toStdString());
        // Força o widget do canvas a se redesenhar com as novas formas
        canvasWidget->update();
    }
}
