#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T05:50:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QmySPIN-Application
TEMPLATE = app


SOURCES += main.cpp\
        myspinwindow.cpp \
    myspinlabel.cpp

HEADERS  += myspinwindow.h \
    myspinlabel.h

FORMS    += myspinwindow.ui
QMAKE_CXXFLAGS += -std=c++11

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/out/lib/ -lprojection-export
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/out/lib/ -lprojection-export
else:unix: LIBS += -L$$PWD/../../../build/out/lib/ -lprojection-export

INCLUDEPATH += $$PWD/../../qmyspin/build/out/lib
DEPENDPATH += $$PWD/../../qmyspin/build/out/lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/out/lib/ -lprojection-handler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/out/debug/ -lprojection-handler
else:unix: LIBS += -L$$PWD/../../../build/out/lib -lprojection-handler

INCLUDEPATH += $$PWD/../../../build/out
DEPENDPATH += $$PWD/../../../build/out

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/out/release/ -ltransport-adapter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/out/debug/ -ltransport-adapter
else:unix: LIBS += -L$$PWD/../../qmyspin/build/out/lib -ltransport-adapter

INCLUDEPATH += $$PWD/../../../build/out
INCLUDEPATH += $$PWD/../../export/include/
DEPENDPATH += $$PWD/../../../build/out

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/out/release/ -lutility
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/out/debug/ -lutility
else:unix: LIBS += -L$$PWD/../../../build/out/lib -lutility

INCLUDEPATH += $$PWD/../../qmyspin/build/out
DEPENDPATH += $$PWD/../../qmyspin/build/out

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../3rdparty/myspin/1.2.3/arm/32bit/debug/lib/release/ -lmySPIN-Core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../3rdparty/myspin/1.2.3/arm/32bit/debug/lib/debug/ -lmySPIN-Core
else:unix: LIBS += -L$$PWD/../../../3rdparty/myspin/1.2.3/arm/32bit/debug/lib/ -lmySPIN-Core

INCLUDEPATH += $$PWD/../../../3rdparty/myspin/1.2.3/arm/32bit/debug/include
DEPENDPATH += $$PWD/../../../3rdparty/myspin/1.2.3/arm/32bit/debug/include
