
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QModelIndex>

#include "ui_mainwindow.h"
#include "model/root.h"
#include "view/achivement.h"

class MindMapScene;
class QAction;
class QTreeView;
class QWidget;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void newAchivement();
	void newActionItem();
	void slotSceneSelectionChanged();
    void updateActions();

private:
    struct Private;
    Private* m_pvt;
	model::RootPtr model;
	MindMapScene*	m_scene;
	view::Achivement* m_selected_achivement;
    QTabWidget* m_tabwidget;
};

#endif
