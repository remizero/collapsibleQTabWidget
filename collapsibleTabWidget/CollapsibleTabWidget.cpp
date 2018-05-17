#include "CollapsibleTabWidget.h"
#include <QDebug>

CollapsibleTabWidget::CollapsibleTabWidget ( QWidget *parent ) : QTabWidget ( parent ) {

  this->setMinimumHeight ( 0 );
  this->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  this->previousIndex = 0;
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

        this->getToggleAnimation ()->setDirection ( this->openTabWidget ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
        this->setOpenTabWidget ( !this->openTabWidget );
        this->getToggleAnimation ()->start ();
      }
    } else {

      this->getToggleAnimation ()->setDirection ( this->openTabWidget ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
      this->setOpenTabWidget ( !this->openTabWidget );
      this->getToggleAnimation ()->start ();
    }
  } else {

    if ( this->currentIndex () != this->previousIndex ) {

      this->previousIndex = this->currentIndex ();
    }
  }
}

void CollapsibleTabWidget::setAnimation () {

  for ( int i = 0; i < toggleAnimation->animationCount () - 1; ++i ) {

    QPropertyAnimation* SectionAnimation = static_cast<QPropertyAnimation *> ( toggleAnimation->animationAt ( i ) );
    SectionAnimation->setDuration ( 300 );
    #ifdef Q_OS_WIN
      SectionAnimation->setStartValue ( this->geometry ().height () - 10 );
    #endif
    #ifdef Q_OS_LINUX
      SectionAnimation->setStartValue ( this->geometry ().height () );
    #endif
    SectionAnimation->setEndValue ( 0 );
  }
  QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *> ( toggleAnimation->animationAt ( toggleAnimation->animationCount () - 1 ) );
  contentAnimation->setDuration ( 300 );
  contentAnimation->setStartValue ( 0 );
  #ifdef Q_OS_WIN
    contentAnimation->setEndValue ( this->tabBar ()->height () - 7 );
  #endif
  #ifdef Q_OS_LINUX
    contentAnimation->setEndValue ( this->tabBar ()->height () );
  #endif
}

void CollapsibleTabWidget::setClosedTabWidget ( bool value ) {

  this->lockedTabWidget = value;
}

void CollapsibleTabWidget::setOpenTabWidget ( bool value ) {

  this->openTabWidget = value;
}

void CollapsibleTabWidget::showEvent ( QShowEvent *event ) {

  if ( event->type () == QEvent::Show ) {

    this->setAnimation ();
  }
}
