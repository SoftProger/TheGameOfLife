#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T19:53:13
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Life
CONFIG   += console C++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    cell.cpp \
    application.cpp \
    Board/board.cpp \
    Board/boardimpl.cpp

HEADERS += \
    game.h \
    cell.h \
    application.h \
    cellstatus.h \
    Board/board.h \
    Board/boardimpl.h
