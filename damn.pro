TEMPLATE = app
QT += core gui

include (view/view.pri)
include (controller/controller.pri)
include (model/model.pri)

SOURCES	+=  main.cpp \
            mainwindow.cpp \

HEADERS	+=  mainwindow.h \
            fwdeclaration.h \
            global.h\

FORMS +=    mainwindow.ui \
            actiondependence.ui


UI_DIR = ./ui/
MOC_DIR = ./moc/
OBJECTS_DIR = ./obj
