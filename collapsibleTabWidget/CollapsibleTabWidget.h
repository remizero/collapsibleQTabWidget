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
#include <QSizePolicy>
#include <QString>
#include <QTabBar>
#include <QTabWidget>
#include <QWidget>

/**
 * http://www.qtcentre.org/threads/11922-Styling-a-QTabWidget
 * http://blog.qt.io/blog/2007/06/22/styling-the-tab-widget/
 * https://stackoverflow.com/questions/45042508/how-to-set-qwidget-in-qtabwidget-header
 * https://stackoverflow.com/questions/44436328/qt-tabwidget-corner-widget-size
 * https://stackoverflow.com/questions/37649177/add-widgets-into-a-qtabwidget/37650578
 * http://developers-club.com/posts/48963/
 *
 * PARA LA ANIMACIÓN DEL COLLAPSE/UNCOLLAPSE DEL MENU
 * https://stackoverflow.com/questions/24106177/how-to-animate-hiding-showing-of-a-qvboxlayout-widget
 * http://doc.qt.io/qt-5/animation-overview.html
 *
 */

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
