TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        histogram.cpp \
        main.cpp \
        randomeintegergenerator.cpp

HEADERS += \
        histogram.h \
        histogrambase.h \
        log.h \
        randomeintegergenerator.h
