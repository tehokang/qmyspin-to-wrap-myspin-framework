#ifndef MYSPINLABEL_H
#define MYSPINLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

class MySPINLabel : public QLabel
{
  Q_OBJECT
public:
  explicit MySPINLabel(QWidget *parent = 0);

  void mouseMoveEvent(QMouseEvent *ev);
  void mousePressEvent(QMouseEvent *ev);
  void mouseReleaseEvent();

  int x;
  int y;
signals:
  void Mouse_Pressed();
  void Mouse_Move();
  void Mouse_Released();

public slots:

};

#endif // MYSPINLABEL_H
