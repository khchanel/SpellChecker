#-------------------------------------------------
#
# Project created by QtCreator 2011-05-27T02:40:32
#
#-------------------------------------------------

QT       += core gui

TARGET = SpellChecker
TEMPLATE = app
LIBS += -lhunspell-1.2


SOURCES += main.cpp\
        spellcheckerwindow.cpp \
    spellchecker.cpp

HEADERS  += spellcheckerwindow.h \
    spellchecker.h

FORMS    += spellcheckerwindow.ui

OTHER_FILES += \
    .gitignore

RESOURCES +=
