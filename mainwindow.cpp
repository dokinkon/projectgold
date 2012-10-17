
#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mindmapscene.h"
#include "controller.h"
#include "view/actiondependenceview.h"
#include "controller/dependenceviewcontroller.h"
#include "model/basemodel.h"


struct MainWindow::Private : public Ui::MainWindow
{
    model::BaseModel model;
    Controller* controller;

    ActionDependenceViewController* m_actionDependenceViewController;

    Private()
        : controller(NULL)
    {
    }
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pvt(new Private)
{
    m_pvt->controller = new Controller(this);
    m_pvt->controller->setModel(&m_pvt->model);

    // setup Ui
    m_pvt->setupUi(this);

    // mindmapview
    QTabWidget* tabWidget = new QTabWidget(this);
    tabWidget->setTabShape(QTabWidget::Triangular);
    QGraphicsView* mindMapView = new QGraphicsView(tabWidget);
    mindMapView->setScene(m_pvt->controller->mindMapScene());
    tabWidget->addTab(mindMapView, tr("MindMap"));

    // actiondependenceview
    view::ActionDependenceView* depView = new view::ActionDependenceView(tabWidget);
    depView->setModel(&m_pvt->model);
    tabWidget->addTab(depView, tr("ActionDependenceView"));

    setCentralWidget(tabWidget);

    m_pvt->m_actionDependenceViewController = new ActionDependenceViewController(this);
    m_pvt->m_actionDependenceViewController->setModelAndView(&m_pvt->model, depView);

    connect(m_pvt->newAchivementAction,
            SIGNAL(triggered()),
            m_pvt->controller,
            SLOT(createAchievement()));

    connect(m_pvt->newActionItemAction,
            SIGNAL(triggered()),
            m_pvt->controller,
            SLOT(createAction()));


    //connect( newAchivementAction, SIGNAL(triggered()), &m_pvt->model, SLOT( createAchivement() ) );

    //connect( newActionItemAction, SIGNAL(triggered()), this, SLOT( newActionItem() ) );
    //connect( m_scene, SIGNAL(selectionChanged()), this, SLOT( slotSceneSelectionChanged() ) );

    //MindMapView -> setScene( m_scene );

    //updateActions();
}

MainWindow::~MainWindow()
{
    delete m_pvt;
}

void MainWindow::newAchivement()
{
    //model::AchivementPtr ach = model -> addAchivement(tr("[no name achivement]"));
    //view::Achivement* item = new view::Achivement( ach );

    //m_scene -> addItem( item );
    //updateActions();
}


void MainWindow::slotSceneSelectionChanged()
{
    updateActions();
}

void MainWindow::updateActions()
{
    //newActionItemAction->setEnabled(false);
    //QList<QGraphicsItem *> items = m_scene->selectedItems();
    //m_selectedAchievement = NULL;
    //foreach( QGraphicsItem* item, items)
    //{
        //view::Achievement* achivement =  qgraphicsitem_cast<view::Achievement*>( item );
        //if( !achivement )
            //continue;

        //m_selectedAchievement  = achivement;
        //newActionItemAction->setEnabled(true);
        //break;
    //}
}

void MainWindow::newActionItem()
{
    //if(!m_selectedAchievement)
    //{
        //ERROR !! do something !!
        //return;
    //}
    /*
    model::ActionPtr act = m_selectedAchievement -> data()-> addAction(tr("[no name action]"));
    view::Action* item = new view::Action( act );
    item->setParentItem(m_selectedAchievement);

    view::Edge* edge = new view::Edge( m_selectedAchievement, item );

    //m_scene -> addItem( item );
    m_scene -> addItem( edge );

    updateActions();
    */
}
