
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QModelIndex>

#include "ui_mainwindow.h"
#include "model/root.h"

class MindMapScene;
class QAction;
class QTreeView;
class QWidget;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
	void newAchivement();

private:
	model::RootPtr model;
	MindMapScene*	m_scene;
};

#endif
