#include "CollapsibleTabWidgetCornerActionsContainer.h"
#include <QDebug> // FOR DEBUGGING MESSAGES

CollapsibleTabWidgetCornerActionsContainer::CollapsibleTabWidgetCornerActionsContainer ( QWidget *parent ) : QWidget ( parent ) {

  this->setContentsMargins ( 0, 0, 0, 0 );
  this->setSizePolicy ( QSizePolicy::Maximum, QSizePolicy::Maximum );

  this->showHideTabWidgetBtn = new QToolButton ( this );
  this->showHideTabWidgetBtn->setObjectName ( "showHideTabWidgetBtn" );
  this->showHideTabWidgetBtn->setSizePolicy ( QSizePolicy::Maximum, QSizePolicy::Maximum );
  this->showHideTabWidgetBtn->setStyleSheet ( "QToolButton {border: none;}" );
  this->showHideTabWidgetBtn->setToolButtonStyle ( Qt::ToolButtonIconOnly );
  //this->showHideTabWidgetBtn->setArrowType ( Qt::ArrowType::DownArrow );
  //this->showHideTabWidgetBtn->setToolTip ( "Collapse" );
  this->showHideTabWidgetBtn->setToolTipDuration ( 5000 );
  this->showHideTabWidgetBtn->setCheckable ( true );
  this->showHideTabWidgetBtn->setChecked ( false );
  this->showHideTabWidgetBtn->setMinimumSize ( 16, 16 );

  this->mainLayout = new QHBoxLayout ( this );
  this->mainLayout->setContentsMargins ( 3, 0, 3, 0 );
  this->mainLayout->addWidget ( this->showHideTabWidgetBtn );
  this->setLayout ( this->mainLayout );
  connect ( this->showHideTabWidgetBtn, SIGNAL ( toggled ( bool ) ), this, SLOT ( toggleShowHideTabWidgetBtn ( bool ) ) );
  this->updateArrowType ();
}

void CollapsibleTabWidgetCornerActionsContainer::updateArrowType () {

  switch ( ( ( QTabWidget * ) this->parentWidget () )->tabPosition () ) {

    case QTabWidget::North: {

      QWidget *corner = ( ( QTabWidget * ) this->parentWidget () )->cornerWidget ( Qt::TopRightCorner );
      if ( corner ) {

        this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::LeftArrow : Qt::ArrowType::DownArrow );

      } else {

        this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::RightArrow : Qt::ArrowType::DownArrow );
      }
      break;
    }
    case QTabWidget::South: {

      QWidget *corner = ( ( QTabWidget * ) this->parentWidget () )->cornerWidget ( Qt::TopRightCorner );
      if ( corner ) {

        this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::LeftArrow : Qt::ArrowType::UpArrow );

      } else {

        this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::RightArrow : Qt::ArrowType::UpArrow );
      }
      break;
    }
    case QTabWidget::East:

      this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::LeftArrow : Qt::ArrowType::DownArrow );
      break;

    case QTabWidget::West:

      this->showHideTabWidgetBtn->setArrowType ( this->showHideTabWidgetBtn->isChecked () ? Qt::ArrowType::LeftArrow : Qt::ArrowType::DownArrow );
      break;

    default:

      break;
  }
  this->showHideTabWidgetBtn->setToolTip ( this->showHideTabWidgetBtn->isChecked () ? "Uncollapse" : "Collapse" );
}

void CollapsibleTabWidgetCornerActionsContainer::toggleShowHideTabWidgetBtn ( bool checked ) {

  this->updateArrowType ();

  //qDebug () << ( ( CollapsibleTabWidget * ) this->parent () )->getOpenTabWidget ();
  //if ( ( ( ( CollapsibleTabWidget * ) this->parent () )->getOpenTabWidget () ) && !( ( ( CollapsibleTabWidget * ) this->parent () )->getLockedTabWidget () ) ) {

  QParallelAnimationGroup *toggleAnimation = ( ( CollapsibleTabWidget * ) this->parent () )->getToggleAnimation ();
  toggleAnimation->setDirection ( checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
  toggleAnimation->start ();
  //}

  ( ( CollapsibleTabWidget * ) this->parent () )->setLockedTabWidget ( checked );
  ( ( CollapsibleTabWidget * ) this->parent () )->setOpenTabWidget ( !checked );
}
