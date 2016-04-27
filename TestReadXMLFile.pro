#-------------------------------------------------
#
# Project created by QtCreator 2016-01-07T15:17:16
#
#-------------------------------------------------

QT       += quick core gui sql xml opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestReadXMLFile
TEMPLATE = app


SOURCES += main.cpp\
        readxml.cpp \
    qtxmlparser.cpp

HEADERS  += readxml.h \
    qtxmlparser.h

CONFIG += mobility
MOBILITY = 

