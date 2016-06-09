#-------------------------------------------------
#
# Project created by QtCreator 2016-01-28T10:38:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cosos
TEMPLATE = app

INCLUDEPATH += /usr/include/
LIBS += -L/usr/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lopencv_videoio -lopencv_calib3d

SOURCES += main.cpp\
    calibrar.cpp


HEADERS  += calibrar.h


OTHER_FILES += \
    Lena.jpg \
    lena.jpg \
