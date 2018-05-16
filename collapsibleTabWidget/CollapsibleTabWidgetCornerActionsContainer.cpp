#include "CollapsibleTabWidgetCornerActionsContainer.h"

// Librerías Internas
#include "CollapsibleTabWidget.h"

#include <QDebug>

CollapsibleTabWidgetCornerActionsContainer::CollapsibleTabWidgetCornerActionsContainer ( QWidget *parent ) : QWidget ( parent ) {

  this->setContentsMargins ( 0, 0, 0, 0 );
  //this->setStyleSheet ( "background-color: black");
  //this->setMinimumHeight ( 16 );
  this->setSizePolicy ( QSizePolicy::Maximum, QSizePolicy::Maximum );

  this->showHideStripeMenuBtn = new QToolButton ( this );
  this->showHideStripeMenuBtn->setObjectName ( "showHideRibbonMenuBtn" );
  this->showHideStripeMenuBtn->setSizePolicy ( QSizePolicy::Maximum, QSizePolicy::Maximum );
  this->showHideStripeMenuBtn->setStyleSheet ( "QToolButton {border: none;}" );
  this->showHideStripeMenuBtn->setToolButtonStyle ( Qt::ToolButtonIconOnly );
  this->showHideStripeMenuBtn->setArrowType ( Qt::ArrowType::DownArrow );
  this->showHideStripeMenuBtn->setToolTip ( "Collapse" );
  this->showHideStripeMenuBtn->setToolTipDuration ( 5000 );
  this->showHideStripeMenuBtn->setCheckable ( true );
  this->showHideStripeMenuBtn->setChecked ( false );
  this->showHideStripeMenuBtn->setMinimumSize ( 16, 16 );

  this->mainLayout = new QHBoxLayout ( this );
  this->mainLayout->setContentsMargins ( 3, 0, 3, 0 );
  this->mainLayout->addWidget ( this->showHideStripeMenuBtn );
  this->setLayout ( this->mainLayout );
  connect ( this->showHideStripeMenuBtn, SIGNAL ( toggled ( bool ) ), this, SLOT ( toggleShowHideStripeMenuBtn ( bool ) ) );
}

void CollapsibleTabWidgetCornerActionsContainer::toggleShowHideStripeMenuBtn ( bool checked ) {

  this->showHideStripeMenuBtn->setArrowType ( checked ? Qt::ArrowType::LeftArrow : Qt::ArrowType::DownArrow );
  this->showHideStripeMenuBtn->setToolTip ( checked ? "Uncollapse" : "Collapse" );

  ( ( CollapsibleTabWidget * ) this->parent () )->setClosedTabWidget ( checked ? true : false );
  ( ( CollapsibleTabWidget * ) this->parent () )->setOpenTabWidget ( checked ? false : true );

  ( ( CollapsibleTabWidget * ) this->parent () )->getToggleAnimation ()->setDirection ( checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
  ( ( CollapsibleTabWidget * ) this->parent () )->getToggleAnimation ()->start ();
}
