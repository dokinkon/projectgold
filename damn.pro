SOURCES	+= main.cpp mainwindow.cpp \
mindmapscene.cpp view/edge.cpp view/item.cpp

HEADERS	+= mainwindow.h global.h\
model/achivement.h model/action.h model/item.h model/root.h \
mindmapscene.h view/achivement.h view/edge.h

FORMS	+= mainwindow.ui


UI_DIR = ./ui/
MOC_DIR = ./.moc/
