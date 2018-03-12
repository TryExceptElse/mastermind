#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T19:48:19
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = testmodel
CONFIG   += console
CONFIG += std=c++14
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += test_model.cpp ../model.cpp
HEADERS += ../model.h
DEFINES += SRCDIR=\\\"$$PWD/\\\"
