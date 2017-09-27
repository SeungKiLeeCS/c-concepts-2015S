TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Word.cpp \
    Wordlist.cpp \
    Uniquelist.cpp \
    Anagramfinder.cpp

HEADERS += \
    Word.h \
    Wordlist.h \
    Uniquelist.h \
    Anagramfinder.h

