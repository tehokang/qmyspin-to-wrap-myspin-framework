#ifndef MYSPINWINDOW_H
#define MYSPINWINDOW_H

#include <QMainWindow>
#include "QmySPIN.h"

namespace Ui {
class mySPINWindow;
}

class mySPINWindow : public QMainWindow, public QmySPINListener
{
    Q_OBJECT

public:
    explicit mySPINWindow(QWidget *parent = 0);
    ~mySPINWindow();

  virtual void onScan(list<Device*> devices) override;
  virtual void onSelect(Device *device) override;
  virtual void onUnselect(Device *device) override;
  virtual void onError(int error) override;
  virtual void onFrameUpdateStarted(unsigned int numOfRectangles) override;
  virtual void onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) override;
  virtual void onFrameUpdateEnded() override;
  virtual void onReady() override;

  void start_qmyspin();

private slots:
  void on_backBtn_pressed();

  void on_backBtn_released();

  void on_menuBtn_pressed();

  void on_menuBtn_released();

  void on_homeBtn_pressed();

  void on_homeBtn_released();

  void on_scanBtn_clicked();

  void on_connectBtn_clicked();

  void on_disconnectBtn_clicked();

  void on_requestFrameBtn_clicked();

  void on_Mouse_pressed();

  void on_Mouse_move();

  void on_Mouse_released();
private:
    Ui::mySPINWindow *ui;

    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 480;
    const unsigned int DPI = 96;

    QmySPIN *m_myspin;
    Device *m_android_device;
};

#endif // MYSPINWINDOW_H
