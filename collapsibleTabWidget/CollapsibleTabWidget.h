#ifndef COLLAPSIBLETABWIDGET_H
#define COLLAPSIBLETABWIDGET_H

// Librerías Internas
#include "collapsibleTabWidget_global.h"
#include "CollapsibleTabWidgetCornerActionsContainer.h"

// Librerías Qt
#include <QFlags>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QSizePolicy>
#include <QString>
#include <QTabBar>
#include <QTabWidget>
#include <QWidget>

class CollapsibleTabWidgetCornerActionsContainer;

class COLLAPSIBLETABWIDGETSHARED_EXPORT CollapsibleTabWidget : public QTabWidget {

    Q_OBJECT

  public:
    explicit CollapsibleTabWidget ( QWidget *parent = Q_NULLPTR );

    bool getLockedTabWidget () const;
    bool getOpenTabWidget () const;
    QParallelAnimationGroup *getToggleAnimation () const;
    void leaveEvent ( QEvent *event ) Q_DECL_OVERRIDE;
    void setAnimation ();
    void setClosedTabWidget ( bool value );
    void setOpenTabWidget ( bool value );

  protected:
    void showEvent ( QShowEvent *event ) Q_DECL_OVERRIDE;

  public slots:
    void launchAnimation ();

  private:
    CollapsibleTabWidgetCornerActionsContainer *cornerActionsContainer;
    QParallelAnimationGroup *toggleAnimation;
    bool lockedTabWidget = false;
    bool openTabWidget = true;
    int previousIndex;
};

#endif // COLLAPSIBLETABWIDGET_H
