#include "editor/MainWindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QKeySequence> //para atalhos do teclado 

MainWindow :: MainWindow(QWidget *parent)
: QMainWindow(parent) // chama o construtor da classe pai 
{
    createActions();//metodos para construir interface
    createMenus();

    setWindowTitle("Editor SVG - Projeto POO");//titulo
    resize(800,600); //tamanho
}
void MainWindow :: createActions()
{
    //cria a acao de "Salvar"
    saveAct = new QAction("&Salvar", this);
    saveAct -> setShortcuts(QKeySequence::Save);//padrao Ctrl + s

    exitAct = new QAction("&Sair", this);
    exitAct -> setShortcuts(QKeySequence::Quit); //Ctrl + Q
}
void MainWindow::createMenus()
{
    filemenu = menuBar()->addMenu("&Arquivo");//adiciona menu de arquivos
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();//linha de separacao
    filemenu->addAction(exitAct);
}