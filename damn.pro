SOURCES	+=  main.cpp \
            mainwindow.cpp \
            mindmapscene.cpp \
            view/baseview.cpp \
            view/edge.cpp \
            view/item.cpp \
            view/actiondependence.cpp \
            model/action.cpp \
            model/basemodel.cpp \
            model/achivement.cpp \
    controller.cpp

HEADERS	+=  mainwindow.h \
            fwdeclaration.h \
            global.h\
            actiondependence.h \
            mindmapscene.h \
            view/achivement.h \
            view/edge.h \
            view/item.h \
            view/baseview.h \
            view/actiondependence.h \
            model/achivement.h \
            model/action.h \
            model/item.h \
            model/root.h \
            model/basemodel.h \
    controller.h

FORMS +=    mainwindow.ui \
            actiondependence.ui


UI_DIR = ./ui/
MOC_DIR = ./.moc/
