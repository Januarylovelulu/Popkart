#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T21:37:41
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Popkart
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += $$PWD/qxtglobal.h \
           $$PWD/qxtglobalshortcut.h \
           $$PWD/qxtglobalshortcut_p.h \
    shortcutchange.h \
    setting.h \
    seamlesssetting.h \
    dpi.h \
    searchquestion.h \
    changeversion.h \
    MyNetwork.h \
    download.h \
    cheackoperatingversion.h \
    chatroom.h
SOURCES += $$PWD/qxtglobalshortcut.cpp \
    shortcutchange.cpp \
    setting.cpp \
    seamlesssetting.cpp \
    dpi.cpp \
    searchquestion.cpp \
    changeversion.cpp \
    MyNetwork.cpp \
    download.cpp \
    cheackoperatingversion.cpp \
    chatroom.cpp
win32{
    SOURCES += $$PWD/qxtglobalshortcut_win.cpp
    LIBS += -luser32
}

SOURCES += \
        ThreadCheckHasNewVersion.cpp \
        ThreadCheckGameIsOpen.cpp \
        main.cpp \
        mainwindow.cpp \
    MyFile.cpp

HEADERS += \
        ThreadCheckHasNewVersion.h \
        ThreadCheckGameIsOpen.h \
        mainwindow.h \
    MyFile.h

FORMS += \
        mainwindow.ui \
    shortcutchange.ui \
    setting.ui \
    seamlesssetting.ui \
    dpi.ui \
    searchquestion.ui \
    changeversion.ui \
    download.ui \
    cheackoperatingversion.ui \
    chatroom.ui

RC_FILE = GameStart.rc

RC_ICONS = icon.ico

RESOURCES += \
    resource.qrc



