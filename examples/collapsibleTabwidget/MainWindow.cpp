#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow ( QWidget *parent ) : QMainWindow ( parent ) {

  this->resize ( 400, 250 );
  CollapsibleTabWidget *collapsibleTabWidget = new CollapsibleTabWidget ( this );

  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 1" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 2" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 3" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 4" );

  collapsibleTabWidget->setTabPosition ( QTabWidget::South );

  this->setCentralWidget ( collapsibleTabWidget );
}
