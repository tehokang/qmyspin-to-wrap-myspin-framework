#include "myspinwindow.h"
#include "ui_myspinwindow.h"
#include <unistd.h>
#include <stdio.h>

#ifdef LOG_DEBUG
#undef LOG_DEBUG
#define LOG_DEBUG qDebug
#endif

void mySPINWindow::onScan(list<Device*> devices) {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
  int counter = 0;
  for ( list<Device*>::iterator it=devices.begin();
      it!=devices.end(); ++it ) {
    Device *device = (Device*)(*it);
    qDebug("[%d] key : %x, product : %s, manufacturer : %s \n",
        ++counter,
        device->getKey(),
        device->getProductName().c_str(),
        device->getManufacturerName().c_str() );

    /**
      * @note Below is just an example, user must be able to choose one of them
      */
    if ( device->getProductName().compare("SAMSUNG_Android") == 0 ) {
      m_android_device = device;
    }
  }
}

void mySPINWindow::onSelect(Device *device) {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
  m_android_device = device;
}

void mySPINWindow::onUnselect(Device *device) {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
  m_android_device = nullptr;
}

void mySPINWindow::onReady() {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
}

void mySPINWindow::onError(int error) {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
}

void mySPINWindow::onFrameUpdateStarted(unsigned int numOfRectangles) {
  qDebug("[%s:%d] rectangles : %d \n", __FUNCTION__, __LINE__, numOfRectangles);

}

#define CASE_2
void mySPINWindow::onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
  unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) {
  qDebug("[%s:%d] currentNumber : %d \n", __FUNCTION__, __LINE__, currentNumber);

#if defined(CASE_1)
  QByteArray byte=QByteArray::fromRawData((char*)buffer, bufferSize );
  QPixmap  pixmap;
  if(pixmap.loadFromData(byte,"BMP"))
  {
      ui->drawLabel->setPixmap(pixmap);
      ui->drawLabel->update();
  }
#elif defined(CASE_2)
  QImage img(buffer, width, height, QImage::Format_RGBA8888);
  ui->drawLabel->setPixmap(QPixmap::fromImage(img));

  static int count = 0;
  char filename[256];
  snprintf(filename, sizeof(filename), "test%d.png", count++);
  img.save(filename);
#elif defined(CASE_3)
  QImage img = QImage::fromData(buffer, bufferSize, "BMP");
  QPixmap pixmap = QPixmap::fromImage(img);
  ui->drawLabel->setPixmap(pixmap);
#endif
}

void mySPINWindow::onFrameUpdateEnded() {
  qDebug("[%s:%d] \n", __FUNCTION__, __LINE__);
  ui->drawLabel->update();
}



mySPINWindow::mySPINWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mySPINWindow),
    m_android_device(nullptr)
{
    ui->setupUi(this);

    connect(ui->drawLabel, SIGNAL(Mouse_Pressed()), this, SLOT(on_Mouse_pressed()));
    connect(ui->drawLabel, SIGNAL(Mouse_Move()), this, SLOT(on_Mouse_move()));
    connect(ui->drawLabel, SIGNAL(Mouse_Released()), this, SLOT(on_Mouse_released()));
}

mySPINWindow::~mySPINWindow()
{
    delete ui;
}

void mySPINWindow::start_qmyspin()
{
    qDebug("Let's go mySPIN! \n");

    unsigned char frame_buffer[WIDTH*HEIGHT*4];
    unsigned char pixel_bytes = 4;
    QmySPIN::PIXEL_FORMAT pixel_format = QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_RGBA8888;

    m_myspin = QmySPIN::createInstance();
    m_myspin->setLogLevel(true, true, true, true);
    m_myspin->setFrameBuffer(pixel_format, pixel_bytes, frame_buffer, WIDTH, HEIGHT, DPI);
    m_myspin->addEventListener(this);

    if ( !m_myspin->init() ||  !m_myspin->start() )
    {
        qDebug("Fail to start QmySPIN \n");
    }
}

void mySPINWindow::on_backBtn_pressed()
{
    m_myspin->sendBackKey(QmySPIN::PRESS_TYPE::PRESS);
}

void mySPINWindow::on_backBtn_released()
{
    m_myspin->sendBackKey(QmySPIN::PRESS_TYPE::RELEASE);
}

void mySPINWindow::on_menuBtn_pressed()
{
    m_myspin->sendMenuKey(QmySPIN::PRESS_TYPE::PRESS);
}

void mySPINWindow::on_menuBtn_released()
{
    m_myspin->sendMenuKey(QmySPIN::PRESS_TYPE::RELEASE);
}

void mySPINWindow::on_homeBtn_pressed()
{
    m_myspin->sendHomeKey(QmySPIN::PRESS_TYPE::PRESS);
}

void mySPINWindow::on_homeBtn_released()
{
    m_myspin->sendHomeKey(QmySPIN::PRESS_TYPE::RELEASE);
}

void mySPINWindow::on_scanBtn_clicked()
{
    m_myspin->scan();
}

void mySPINWindow::on_connectBtn_clicked()
{
    m_myspin->select(m_android_device);
}

void mySPINWindow::on_disconnectBtn_clicked()
{
    m_myspin->unselect(m_android_device);
}

void mySPINWindow::on_requestFrameBtn_clicked()
{
    m_myspin->requestFrameBuffer();
}

void mySPINWindow::on_Mouse_pressed()
{
  qDebug("[PRESS] x : %d, y : %d \n", ui->drawLabel->x, ui->drawLabel->y);
  m_myspin->sendTouch(ui->drawLabel->x, ui->drawLabel->y, 1, QmySPIN::PRESS_TYPE::PRESS);
}

void mySPINWindow::on_Mouse_move()
{
//  qDebug("[MOVE] x : %d, y : %d \n", ui->drawLabel->x, ui->drawLabel->y);
//  m_myspin->sendTouch(ui->drawLabel->x, ui->drawLabel->y, 1, QmySPIN::PRESS_TYPE::MOVE);
}

void mySPINWindow::on_Mouse_released()
{
  qDebug("[RELEASE] x : %d, y : %d \n", ui->drawLabel->x, ui->drawLabel->y);
  m_myspin->sendTouch(ui->drawLabel->x, ui->drawLabel->y, 1, QmySPIN::PRESS_TYPE::RELEASE);

}
