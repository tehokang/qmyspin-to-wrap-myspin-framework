#include "myspinlabel.h"

MySPINLabel::MySPINLabel(QWidget *parent) :
  QLabel(parent)
{
}

void MySPINLabel::mouseMoveEvent(QMouseEvent *ev)
{
  x = ev->x();
  y = ev->y();
  emit Mouse_Move();
}

void MySPINLabel::mousePressEvent(QMouseEvent *ev)
{
  x = ev->x();
  y = ev->y();
  emit Mouse_Pressed();
}

void MySPINLabel::mouseReleaseEvent()
{
  emit Mouse_Released();
}
