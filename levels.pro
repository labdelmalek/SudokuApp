#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T22:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = levels
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    levelselect.cpp \
    levelkids.cpp \
    sudokuadult.cpp \
    adulteasy.cpp \
    expert.cpp \
    classe1616.cpp \
    sudoku1212.cpp \
    howtoplay.cpp

HEADERS += \
        mainwindow.h \
    levelselect.h \
    levelkids.h \
    kidscode.h \
    sudokuadult.h \
    classsudoku.h \
    adulteasy.h \
    expert.h \
    classe1616.h \
    code16.h \
    sudoku1212.h \
    code12.h \
    howtoplay.h

FORMS += \
        mainwindow.ui \
    levelselect.ui \
    levelkids.ui \
    sudokuadult.ui \
    adulteasy.ui \
    expert.ui \
    classe1616.ui \
    sudoku1212.ui \
    howtoplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
