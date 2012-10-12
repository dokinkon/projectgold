TEMPLATE = app

include (view/view.pri)
include (model/model.pri)

SOURCES	+=  main.cpp \
            mainwindow.cpp \
            mindmapscene.cpp \
            controller.cpp \

HEADERS	+=  mainwindow.h \
            fwdeclaration.h \
            global.h\
            mindmapscene.h \
            controller.h \

FORMS +=    mainwindow.ui \
            actiondependence.ui


UI_DIR = ./ui/
MOC_DIR = ./moc/
OBJECTS_DIR = ./obj
