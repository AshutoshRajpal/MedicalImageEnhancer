QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17
QMAKE_CXXFLAGS += -Wno-deprecated-declarations

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += /opt/homebrew/opt/opencv/include/opencv4
LIBS += -L/opt/homebrew/opt/opencv/lib -lopencv_core -lopencv_imgproc -lopencv_highgui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
