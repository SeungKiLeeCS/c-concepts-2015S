TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Package.cpp \
    Ground.cpp \
    Twoday.cpp \
    Overnight.cpp \
    Display.cpp

HEADERS += \
    Package.h \
    Ground.h \
    Twoday.h \
    Overnight.h \
    Display.h

