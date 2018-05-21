#ifndef COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
#define COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H

// Librerias Internas
#include "CollapsibleTabWidget.h"

// Librerías Qt
#include <QAbstractAnimation>
#include <QAction>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QTabWidget>
#include <QToolButton>
#include <QWidget>

class CollapsibleTabWidgetCornerActionsContainer : public QWidget {

    Q_OBJECT

  public:
    explicit CollapsibleTabWidgetCornerActionsContainer ( QWidget *parent = 0 );
    void updateArrowType ();

  public slots:
    void toggleShowHideTabWidgetBtn ( bool checked );

  private:
    QToolButton *showHideTabWidgetBtn;
    QHBoxLayout *mainLayout;
};

#endif // COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
