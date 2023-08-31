TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
DEFINES -= UNICODE
DEFINES += UMBCS
QMAKE_CXXFLAGS -= -Zc:strictStrings

SOURCES += \
        main.cpp

HEADERS += \
    Hanoi.h \
    LeeCode.h \
    Sort.h
