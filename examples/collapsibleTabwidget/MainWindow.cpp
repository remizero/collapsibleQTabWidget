#include "MainWindow.h"

MainWindow::MainWindow ( QWidget *parent ) : QMainWindow ( parent ) {

  this->resize ( 400, 130 );
  CollapsibleTabWidget *collapsibleTabWidget = new CollapsibleTabWidget ( this );

  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 1" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 2" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 3" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 4" );

  this->setCentralWidget ( collapsibleTabWidget );
}

//TODO: Adaptar el código para poder ser utilizado desde QtDesigner.
//TODO: Adaptar el código a qt-plugin-system.
//TODO: Hacer de forma transparente, que al colapsar el QTabWidget se redimensione su contenedor padre.
// Al colapsar el QTabWidget, permitir se redimensione el contenedor padre no está implementado aun.
// TODO: Documentar el código.
// TODO: Hasta ahora hay que definir un MaximunHeight y un tamaño inicial igual a MaximunHeight para evitar discrepancias en la animación
