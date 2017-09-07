#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T14:05:47
#
#-------------------------------------------------

QT       += core gui avwidgets
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
    interface_control/PwhManagementRibbon.cc \
    interface_control/global_widget.cpp \
    view/table_view.cpp \
    data_veryfication.cpp \
    interface_control/detail_dlg.cpp \
    interface_control/data_widget.cpp \
    interface_control/form_widget.cpp \
    video/video_form_split.cpp \
    interface_control/analysis_detail_widget.cpp \
    Model/pts_model.cpp \
    Model/pts_delegate.cpp \
    code_edit.cpp \
    video/video_form_model.cpp \
    video/video_delegate.cpp \
    Model/stdtime_model.cpp \
    delegate/stdtime_delegate.cpp \
    interface_control/modify_product_dlg.cpp \
    interface_control/new_item_dlg.cpp \
    video/video_widget.cpp \
    video/progress_label.cpp \
    util.cpp \
    Model/TreeModel.cpp \
    Model/TreeItem.cpp \
    interface_control/ModifyProductDlg.cpp \
    interface_control/AddtoStdDatabaseDlg.cpp

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
    interface_control/PwhManagementRibbon.h \
    interface_control/global_widget.h \
    view/table_view.h \
    data_veryfication.h \
    interface_control/detail_dlg.h \
    interface_control/data_widget.h \
    interface_control/form_widget.h \
    video/video_form_split.h \
    interface_control/analysis_detail_widget.h \
    Model/pts_model.h \
    Model/pts_delegate.h \
    code_edit.h \
    video/video_form_model.h \
    video/video_delegate.h \
    Model/stdtime_model.h \
    delegate/stdtime_delegate.h \
    arithmetic_resource.hpp \
    interface_control/modify_product_dlg.h \
    interface_control/new_item_dlg.h \
    video/video_widget.h \
    video/video_player.hpp \
    video/progress_label.h \
    util.h \
    Model/TreeModel.h \
    Model/TreeItem.h \
    interface_control/ModifyProductDlg.h \
    interface_control/AddtoStdDatabaseDlg.h

FORMS    += pwhmanagementmain.ui \
    Pwh/pwhmanagement.ui \
    interface_control/global_widget.ui \
    interface_control/detail_dlg.ui \
    interface_control/data_widget.ui \
    interface_control/form_widget.ui \
    interface_control/analysis_detail_widget.ui \
    interface_control/modify_product_dlg.ui \
    new_file.ui \
    video/video_widget.ui \
    interface_control/modifyproductdlg.ui \
    interface_control/addtostddatabasedlg.ui

LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_thread
LIBS += -lboost_regex
