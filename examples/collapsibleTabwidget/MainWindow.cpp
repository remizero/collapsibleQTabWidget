#include "MainWindow.h"
#include <QDebug>
#include <QSplitter>
#include <QTextEdit>

MainWindow::MainWindow ( QWidget *parent ) : QMainWindow ( parent ) {

  this->resize ( 400, 250 );
  CollapsibleTabWidget *collapsibleTabWidget = new CollapsibleTabWidget ( this );

  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 1" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 2" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 3" );
  collapsibleTabWidget->addTab ( new QWidget ( this ), "Tab 4" );

  collapsibleTabWidget->setTabPosition ( QTabWidget::North );
  //collapsibleTabWidget->setTabPosition ( QTabWidget::West );

  QSplitter *splitter = new QSplitter ( this );
  splitter->setOrientation ( Qt::Vertical );
  splitter->addWidget ( collapsibleTabWidget );
  splitter->addWidget ( new QTextEdit ( this ) );

  this->setCentralWidget ( splitter );
}
