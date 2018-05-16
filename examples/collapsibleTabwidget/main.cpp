// Librerías Internas
#include "MainWindow.h"

// Librerías Qt
#include <QApplication>

int main ( int argc, char *argv [] ) {

  QApplication app ( argc, argv );
  app.setApplicationName ( "My Collapsible QTabWidget" );

  MainWindow mainWindow;
  mainWindow.show ();

  return app.exec ();
}
