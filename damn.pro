SOURCES	+=  main.cpp \
            mainwindow.cpp \
            mindmapscene.cpp \
            controller.cpp \
            view/baseview.cpp \
            view/edge.cpp \
            view/item.cpp \
            view/actiondependence.cpp \
            view/achievement.cpp \
            model/action.cpp \
            model/basemodel.cpp \
            model/achievement.cpp \
            model/item.cpp

HEADERS	+=  mainwindow.h \
            fwdeclaration.h \
            global.h\
            actiondependence.h \
            mindmapscene.h \
            controller.h \
            view/edge.h \
            view/item.h \
            view/baseview.h \
            view/actiondependence.h \
            view/achievement.h \
            model/action.h \
            model/item.h \
            model/root.h \
            model/basemodel.h \
            model/achievement.h

FORMS +=    mainwindow.ui \
            actiondependence.ui


UI_DIR = ./ui/
MOC_DIR = ./.moc/
