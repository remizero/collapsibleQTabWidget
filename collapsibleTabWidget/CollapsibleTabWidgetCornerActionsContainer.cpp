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
  this->showHideTabWidgetBtn->setArrowType ( Qt::ArrowType::DownArrow );
  this->showHideTabWidgetBtn->setToolTip ( "Collapse" );
  this->showHideTabWidgetBtn->setToolTipDuration ( 5000 );
  this->showHideTabWidgetBtn->setCheckable ( true );
  this->showHideTabWidgetBtn->setChecked ( false );
  this->showHideTabWidgetBtn->setMinimumSize ( 16, 16 );

  this->mainLayout = new QHBoxLayout ( this );
  this->mainLayout->setContentsMargins ( 3, 0, 3, 0 );
  this->mainLayout->addWidget ( this->showHideTabWidgetBtn );
  this->setLayout ( this->mainLayout );
  connect ( this->showHideTabWidgetBtn, SIGNAL ( toggled ( bool ) ), this, SLOT ( toggleShowHideTabWidgetBtn ( bool ) ) );
}

void CollapsibleTabWidgetCornerActionsContainer::toggleShowHideTabWidgetBtn ( bool checked ) {

  this->showHideTabWidgetBtn->setArrowType ( checked ? Qt::ArrowType::LeftArrow : Qt::ArrowType::DownArrow );
  this->showHideTabWidgetBtn->setToolTip ( checked ? "Uncollapse" : "Collapse" );

  ( ( CollapsibleTabWidget * ) this->parent () )->setClosedTabWidget ( checked ? true : false );
  ( ( CollapsibleTabWidget * ) this->parent () )->setOpenTabWidget ( checked ? false : true );

  ( ( CollapsibleTabWidget * ) this->parent () )->getToggleAnimation ()->setDirection ( checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward );
  ( ( CollapsibleTabWidget * ) this->parent () )->getToggleAnimation ()->start ();
}
