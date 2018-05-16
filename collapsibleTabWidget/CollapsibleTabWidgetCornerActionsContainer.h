#ifndef COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
#define COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H

// Librerías Qt
#include <QAbstractAnimation>
#include <QAction>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QToolButton>
#include <QWidget>

//class CollapsibleTabWidget;

class CollapsibleTabWidgetCornerActionsContainer : public QWidget {

    Q_OBJECT

  public:
    explicit CollapsibleTabWidgetCornerActionsContainer ( QWidget *parent = 0 );

  public slots:
    void toggleShowHideStripeMenuBtn ( bool checked );

  private:
    QToolButton *showHideStripeMenuBtn;
    QHBoxLayout *mainLayout;
};

#endif // COLLAPSIBLETABWIDGETCORNERACTIONSCONTAINER_H
