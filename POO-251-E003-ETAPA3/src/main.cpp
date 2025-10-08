
#include "editor/MainWindow.h"
#include <QApplication>

#include "editor/Canvas.h"
#include "editor/Point.h"
#include "editor/Polygon.h"
#include "editor/EditorController.h"
#include "editor/CLIView.h"
#include <vector>
#include <memory>
int  main(int argc, char *argv[])
{
    QApplication app(argc, argv);//cria o objeto da aplicação

    Canvas canvasModel;

    CLIView view;

    EditorController controller(canvasModel, view);

    MainWindow window(canvasModel, controller); //cria uma instancia de janela
    window.show();//torna a janela visivel

    return app.exec();//inicia o loop de eventos do app

}
