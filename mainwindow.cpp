
#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/actiondependenceview.h"
#include "view/mindmapview.h"
#include "controller/dependenceviewcontroller.h"
#include "controller/mindmapviewcontroller.h"
#include "model/basemodel.h"


struct MainWindow::Private : public Ui::MainWindow
{
    model::BaseModel model;

    MindMapViewController* m_mindMapViewController;
    ActionDependenceViewController* m_actionDependenceViewController;

    Private()
        : m_mindMapViewController(NULL)
        , m_actionDependenceViewController(NULL)
    {
    }
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pvt(new Private)
{
    // setup Ui
    m_pvt->setupUi(this);
    QTabWidget* tabWidget = new QTabWidget(this);
    tabWidget->setTabShape(QTabWidget::Triangular);

    // mindmapview
    view::MindMapView* mindMapView = new view::MindMapView(tabWidget);
    m_pvt->m_mindMapViewController = new MindMapViewController(this);
    m_pvt->m_mindMapViewController->setModelAndView(&m_pvt->model, mindMapView);
    tabWidget->addTab(mindMapView, tr("MindMap"));

    // actiondependenceview
    view::ActionDependenceView* depView = new view::ActionDependenceView(tabWidget);
    m_pvt->m_actionDependenceViewController = new ActionDependenceViewController(this);
    m_pvt->m_actionDependenceViewController->setModelAndView(&m_pvt->model, depView);
    tabWidget->addTab(depView, tr("ActionDependenceView"));

    setCentralWidget(tabWidget);


    connect(m_pvt->newAchivementAction,
            SIGNAL(triggered()),
            m_pvt->m_mindMapViewController,
            SLOT(createAchievement()));

    connect(m_pvt->newActionItemAction,
            SIGNAL(triggered()),
            m_pvt->m_mindMapViewController,
            SLOT(createAction()));


    //updateActions();
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotSceneSelectionChanged()
{
    updateActions();
}

void MainWindow::updateActions()
{
}

