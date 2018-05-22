#include "CollapsibleTabWidget.h"
#include <QDebug>

CollapsibleTabWidget::CollapsibleTabWidget ( QWidget *parent ) : QTabWidget ( parent ) {

  // TODO: Por si desaparece el cornerWidget
  // https://stackoverflow.com/questions/18144626/qtabwidget-corner-qtoolbutton-widget-disappearing
  // http://www.qtcentre.org/threads/12539-QTabWidget-corner-widget-is-not-shown
  // http://doc.qt.io/qt-5/qstyle.html#subElementRect
  // http://doc.qt.io/qt-5/qstyle.html#SubElement-enum
  // http://doc.qt.io/qt-5/qstyleoption.html
  // http://doc.qt.io/qt-5/style-reference.html
  //
  // https://code.woboq.org/qt5/qtbase/src/widgets/widgets/qtabwidget.cpp.html
  // https://code.woboq.org/qt5/qtbase/src/widgets/widgets/qtabwidget.h.html
  this->timerId = 0;
  this->setMinimumHeight ( 0 );
  this->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  this->previousIndex = 0;
  this->openTabWidget = true;
  this->setCurrentIndex ( 0 );
  this->cornerActionsContainer = new CollapsibleTabWidgetCornerActionsContainer ( this );
  this->setCornerWidget ( this->cornerActionsContainer, Qt::TopRightCorner );

  // allows the entire widget to expand or contract with its content
  this->toggleAnimation = new QParallelAnimationGroup ( this );
  this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "minimumHeight" ) );
  this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "maximumHeight" ) );

  connect ( this, SIGNAL ( tabBarClicked ( int ) ), this, SLOT ( setCurrentIndex ( int ) ) );
  connect ( this, SIGNAL ( tabBarClicked ( int ) ), this, SLOT ( launchAnimation () ) );
}

bool CollapsibleTabWidget::getLockedTabWidget () const {

  return this->lockedTabWidget;
}

bool CollapsibleTabWidget::getOpenTabWidget () const {

  return this->openTabWidget;
}

QParallelAnimationGroup *CollapsibleTabWidget::getToggleAnimation () const {

  return this->toggleAnimation;
}

void CollapsibleTabWidget::leaveEvent ( QEvent *event ) {

  if ( event->type () == QEvent::Leave ) {

    if ( this->openTabWidget ) {

      this->launchAnimation ();
    }
  }
  QWidget::leaveEvent ( event );
}

void CollapsibleTabWidget::launchAnimation () {

  if ( this->lockedTabWidget ) {

    if ( this->currentIndex () != this->previousIndex ) {

      this->previousIndex = this->currentIndex ();
      if ( !this->openTabWidget ) {

        this->toggleAnimation->setDirection ( this->openTabWidget ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
        this->setOpenTabWidget ( !this->openTabWidget );
        this->toggleAnimation->start ();
      }
    } else {

      this->toggleAnimation->setDirection ( this->openTabWidget ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
      this->setOpenTabWidget ( !this->openTabWidget );
      this->toggleAnimation->start ();
    }
  } else {

    if ( this->currentIndex () != this->previousIndex ) {

      this->previousIndex = this->currentIndex ();
    }
  }
}

int CollapsibleTabWidget::getPreviousHeight () const {

  return this->previousHeight;
}

void CollapsibleTabWidget::setPreviousHeight ( int value ) {

  this->previousHeight = value;
}

void CollapsibleTabWidget::setTabPosition ( QTabWidget::TabPosition tabPosition ) {

  QTabWidget::setTabPosition ( tabPosition );
  this->cornerActionsContainer->updateArrowType ();
}

void CollapsibleTabWidget::timerEvent ( QTimerEvent *timerEvent ) {

  qDebug () << "Entró por la línea 99";
  if ( !this->lockedTabWidget ) {

    switch ( this->tabPosition () ) {

      case QTabWidget::North:

        qDebug () << "entró por el norte";
        this->previousHeight = this->geometry ().height ();
        this->setAnimation ();
        this->setMinimumHeight ( 0 );
        this->setMaximumHeight ( 16777215 );
        break;

      case QTabWidget::South:

        qDebug () << "entró por el sur";
        this->previousHeight = this->geometry ().height ();
        this->setAnimation ();
        this->setMinimumHeight ( 0 );
        this->setMaximumHeight ( 16777215 );
        break;

      case QTabWidget::East:

        qDebug () << "entró por el este";
        this->previousHeight = this->geometry ().width ();
        this->setAnimation ();
        this->setMinimumWidth ( 0 );
        this->setMaximumWidth ( 16777215 );
        break;

      case QTabWidget::West:

        qDebug () << "entró por el oeste";
        this->previousHeight = this->geometry ().width ();
        this->setAnimation ();
        this->setMinimumWidth ( 0 );
        this->setMaximumWidth ( 16777215 );
        break;

      default:
        break;
    }
  } else {

    switch ( this->tabPosition () ) {

      case QTabWidget::North:

        qDebug () << "entró por el norte";
        if ( this->maximumHeight () != this->parentWidget ()->geometry ().height () ) {

          this->setAnimation ();
        }
        break;

      case QTabWidget::South:

        qDebug () << "entró por el sur";
        if ( this->maximumHeight () != this->parentWidget ()->geometry ().height () ) {

          this->setAnimation ();
        }
        break;

      case QTabWidget::East:

        qDebug () << "entró por el este";
        if ( this->maximumWidth () != this->parentWidget ()->geometry ().width () ) {

          this->setAnimation ();
        }
        break;

      case QTabWidget::West:

        qDebug () << "entró por el oeste";
        if ( this->maximumWidth () != this->parentWidget ()->geometry ().width () ) {

          this->setAnimation ();
        }
        break;

      default:

        if ( this->maximumHeight () != this->parentWidget ()->geometry ().height () ) {

          this->setAnimation ();
        }
        break;
    }
  }
  this->killTimer ( timerEvent->timerId () );
  this->timerId = 0;
  qDebug () << "this->previousHeight" << this->previousHeight;
}

void CollapsibleTabWidget::resizeEvent ( QResizeEvent *event ) {

  qDebug () << "Entró por la línea 121";
  if ( this->timerId ) {

    this->killTimer ( this->timerId );
    this->timerId = 0;
  }
  this->timerId = this->startTimer ( 50 ); // delay beetween ends of resize and your action
  QTabWidget::resizeEvent ( event );
  qDebug () << "this->previousHeight" << this->previousHeight;
}

void CollapsibleTabWidget::setAnimation () {

  /*switch ( this->tabPosition () ) {

    case QTabWidget::North: {

      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "minimumHeight" ) );
      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "maximumHeight" ) );
      QPropertyAnimation *SectionAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 0 ) );
      SectionAnimation->setDuration ( 300 );
      SectionAnimation->setStartValue ( this->previousHeight );
      SectionAnimation->setEndValue ( 0 );
      QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 1 ) );
      contentAnimation->setDuration ( 300 );
      contentAnimation->setStartValue ( 0 );
      contentAnimation->setEndValue ( this->tabBar ()->height () );
      break;
    }
    case QTabWidget::South: {

      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "minimumHeight" ) );
      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "maximumHeight" ) );
      QPropertyAnimation *SectionAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 0 ) );
      SectionAnimation->setDuration ( 300 );
      SectionAnimation->setStartValue ( this->previousHeight );
      SectionAnimation->setEndValue ( 0 );
      QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 1 ) );
      contentAnimation->setDuration ( 300 );
      contentAnimation->setStartValue ( 0 );
      contentAnimation->setEndValue ( this->tabBar ()->height () );
      break;
    }
    case QTabWidget::East: {

      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "minimumWidth" ) );
      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "maximumWidth" ) );
      QPropertyAnimation *SectionAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 0 ) );
      SectionAnimation->setDuration ( 300 );
      SectionAnimation->setStartValue ( this->previousHeight );
      SectionAnimation->setEndValue ( 0 );
      QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 1 ) );
      contentAnimation->setDuration ( 300 );
      contentAnimation->setStartValue ( 0 );
      contentAnimation->setEndValue ( this->tabBar ()->height () );
      break;
    }
    case QTabWidget::West: {

      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "minimumWidth" ) );
      this->toggleAnimation->addAnimation ( new QPropertyAnimation ( this, "maximumWidth" ) );
      QPropertyAnimation *SectionAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 0 ) );
      SectionAnimation->setDuration ( 300 );
      SectionAnimation->setStartValue ( this->previousHeight );
      SectionAnimation->setEndValue ( 0 );
      QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( 1 ) );
      contentAnimation->setDuration ( 300 );
      contentAnimation->setStartValue ( 0 );
      contentAnimation->setEndValue ( this->tabBar ()->height () );
      break;
    }
    default:
      break;
  }*/

  for ( int i = 0; i < toggleAnimation->animationCount () - 1; ++i ) {

    QPropertyAnimation *SectionAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( i ) );
    SectionAnimation->setDuration ( 300 );
    SectionAnimation->setStartValue ( this->previousHeight );
    SectionAnimation->setEndValue ( 0 );
  }
  QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( this->toggleAnimation->animationAt ( this->toggleAnimation->animationCount () - 1 ) );
  contentAnimation->setDuration ( 300 );
  contentAnimation->setStartValue ( 0 );
  contentAnimation->setEndValue ( this->tabBar ()->height () );
}

void CollapsibleTabWidget::setCornerWidget ( QWidget *widget, Qt::Corner corner ) {

  QTabWidget::setCornerWidget ( widget, corner );
  ( ( CollapsibleTabWidgetCornerActionsContainer * ) widget )->updateArrowType ();
}

void CollapsibleTabWidget::setLockedTabWidget ( bool value ) {

  this->lockedTabWidget = value;
}

void CollapsibleTabWidget::setOpenTabWidget ( bool value ) {

  this->openTabWidget = value;
}
