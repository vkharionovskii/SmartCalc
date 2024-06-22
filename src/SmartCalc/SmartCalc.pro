QT       += core gui widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Controller.cc \
    ../Model.cc \
    creditcalc.cc \
    depositcalc.cc \
    graph.cc \
    main.cc \
    mainwindow.cc \
    qcustomplot.cpp

HEADERS += \
    ../Controller.h \
    ../Model.h \
    ../Token.h \
    creditcalc.h \
    depositcalc.h \
    graph.h \
    mainwindow.h \
    qcustomplot.h \
    config.h

FORMS += \
    creditcalc.ui \
    depositcalc.ui \
    graph.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
