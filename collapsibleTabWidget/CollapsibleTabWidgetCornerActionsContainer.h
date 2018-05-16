#ifndef COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
#define COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H

// Librerias Internas
#include "CollapsibleTabWidget.h"

// Librerías Qt
#include <QAbstractAnimation>
#include <QAction>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QToolButton>
#include <QWidget>

class CollapsibleTabWidgetCornerActionsContainer : public QWidget {

    Q_OBJECT

  public:
    explicit CollapsibleTabWidgetCornerActionsContainer ( QWidget *parent = 0 );

  public slots:
    void toggleShowHideTabWidgetBtn ( bool checked );

  private:
    QToolButton *showHideTabWidgetBtn;
    QHBoxLayout *mainLayout;
};

#endif // COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
