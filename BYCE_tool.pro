#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T21:14:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BYCE_tool
TEMPLATE = app

CONFIG += serialport

SOURCES += main.cpp\
        mainwindow.cpp \
    windowoptions.cpp \
    3rdparty/libmodbus/modbus-tcp.c \
    3rdparty/libmodbus/modbus-rtu.c \
    3rdparty/libmodbus/modbus-data.c \
    3rdparty/libmodbus/modbus.c \
    3rdparty/qModMaster/rawdatamodel.cpp \
    3rdparty/qModMaster/rawdatadelegate.cpp \
    3rdparty/qModMaster/modbusadapter.cpp \
    3rdparty/qModMaster/busmonitor.cpp \
    3rdparty/qModMaster/registersmodel.cpp \
    3rdparty/qModMaster/eutils.cpp \
    eswitchwindow.cpp

HEADERS  += mainwindow.h \
    windowoptions.h \
    3rdparty/libmodbus/modbus-version.h \
    3rdparty/libmodbus/modbus-tcp-private.h \
    3rdparty/libmodbus/modbus-tcp.h \
    3rdparty/libmodbus/modbus-rtu-private.h \
    3rdparty/libmodbus/modbus-rtu.h \
    3rdparty/libmodbus/modbus-private.h \
    3rdparty/libmodbus/modbus.h \
    3rdparty/libmodbus/config.h \
    3rdparty/qModMaster/rawdatamodel.h \
    3rdparty/qModMaster/rawdatadelegate.h \
    3rdparty/qModMaster/modbusadapter.h \
    3rdparty/qModMaster/busmonitor.h \
    3rdparty/qModMaster/registersmodel.h \
    3rdparty/qModMaster/eutils.h \
    eswitchwindow.h

FORMS    += mainwindow.ui \
    windowoptions.ui \
    3rdparty/qModMaster/busmonitor.ui \
    eswitchwindow.ui


INCLUDEPATH += 3rdparty/libmodbus 3rdparty/qModMaster

win32 {
    LIBS += -lsetupapi -luuid -ladvapi32
}
unix:!macx {
    LIBS += -ludev
}

RESOURCES += \
    ./data/qModMaster.qrc
