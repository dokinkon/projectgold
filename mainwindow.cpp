
#include <QtGui>

#include "mainwindow.h"
#include "mindmapscene.h"
#include "view/actiondependence.h"
#include "view/achivement.h"
#include "view/action.h"
#include "view/edge.h"
#include "model/basemodel.h"


struct MainWindow::Private
{
    model::BaseModel model;
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
	, m_scene( new MindMapScene(this) )
    , m_pvt(new Private)
{
    setupUi(this);

    m_tabwidget = new QTabWidget(this);
    setCentralWidget(m_tabwidget);
    m_tabwidget->setTabShape(QTabWidget::Triangular);
    QGraphicsView* mindMapView = new QGraphicsView(m_tabwidget);
    m_tabwidget->addTab(mindMapView, tr("MindMap"));
    mindMapView->setScene(m_scene);

    view::ActionDependence* depView = new view::ActionDependence(m_tabwidget);
    depView->setModel(&m_pvt->model);
    m_tabwidget->addTab(depView, tr("ActionDependence"));

    model = model::RootPtr( new model::Root() );

    connect( newAchivementAction, SIGNAL(triggered()), this, SLOT( newAchivement() ) );
    connect( newAchivementAction, SIGNAL(triggered()), &m_pvt->model, SLOT( createAchivement() ) );

    connect( newActionItemAction, SIGNAL(triggered()), this, SLOT( newActionItem() ) );
	connect( m_scene, SIGNAL(selectionChanged()), this, SLOT( slotSceneSelectionChanged() ) );

    //MindMapView -> setScene( m_scene );

    updateActions();
}

MainWindow::~MainWindow()
{
    delete m_pvt;
}

void MainWindow::newAchivement()
{
	model::AchivementPtr ach = model -> addAchivement(tr("[no name achivement]"));
	view::Achivement* item = new view::Achivement( ach );

	m_scene -> addItem( item );
	updateActions();
}


void MainWindow::slotSceneSelectionChanged()
{
	updateActions();
}

void MainWindow::updateActions()
{
	newActionItemAction->setEnabled(false);
	QList<QGraphicsItem *> items = m_scene->selectedItems();
	m_selected_achivement = NULL;
	foreach( QGraphicsItem* item, items)
	{
		view::Achivement* achivement =  qgraphicsitem_cast<view::Achivement*>( item );
		if( !achivement )
			continue;

		m_selected_achivement  = achivement;
		newActionItemAction->setEnabled(true);
		break;
	}
}

void MainWindow::newActionItem()
{
	if(!m_selected_achivement)
	{
		//ERROR !! do something !!
		return;
	}
	model::ActionPtr act = m_selected_achivement -> data()-> addAction(tr("[no name action]"));
	view::Action* item = new view::Action( act );
    item->setParentItem(m_selected_achivement);

	view::Edge* edge = new view::Edge( m_selected_achivement, item );

	//m_scene -> addItem( item );
	m_scene -> addItem( edge );

	updateActions();
}
