#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Librerías Externas
#include "CollapsibleTabWidget.h"

// Librerías Qt
#include <QMainWindow>

class MainWindow : public QMainWindow {

    Q_OBJECT

  public:
    explicit MainWindow ( QWidget *parent = 0 );
};

#endif // MAINWINDOW_H
