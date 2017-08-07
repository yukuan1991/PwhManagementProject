#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T14:05:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   -= c++11
QMAKE_CXXFLAGS += -std=c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PwhManagementProject
TEMPLATE = app

DEFINES += PRODUCT_PATH=\\\"./product\\\"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cc\
        PwhManagementMain.cc \
    Pwh/PwhManagement.cc \
    Model/json_model.cpp \
    Model/product_info_model.cpp \
    Model/product_structure_model.cpp \
    Qt-Utils/des.cpp \
    Qt-Utils/encryption.cpp \
    Qt-Utils/tinyxml2.cpp \
    interface_control/Ribbon.cc \
    interface_control/PwhManagementRibbon.cc

HEADERS  += PwhManagementMain.h \
    Pwh/PwhManagement.h \
    Model/json_model.h \
    Model/product_info_model.h \
    Model/product_structure_model.h \
    Qt-Utils/des.h \
    Qt-Utils/encryption.h \
    Qt-Utils/json.hpp \
    Qt-Utils/krys_application.hpp \
    Qt-Utils/qt.hpp \
    Qt-Utils/stl_extension.hpp \
    Qt-Utils/tinyxml2.h \
    interface_control/Ribbon.h \
    interface_control/PwhManagementRibbon.h

FORMS    += pwhmanagementmain.ui \
    Pwh/pwhmanagement.ui

LIBS += -lboost_filesystem
LIBS += -lboost_system
