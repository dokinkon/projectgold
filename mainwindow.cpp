
#include <QtGui>

#include "mainwindow.h"
#include "mindmapscene.h"
#include "view/achivement.h"
#include "view/action.h"
#include "view/edge.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
	, m_scene( new MindMapScene(this) )
{
    setupUi(this);

    model = model::RootPtr( new model::Root() );

    connect( newAchivementAction, SIGNAL(triggered()), this, SLOT( newAchivement() ) );
    connect( newActionItemAction, SIGNAL(triggered()), this, SLOT( newActionItem() ) );
	connect( m_scene, SIGNAL(selectionChanged()), this, SLOT( slotSceneSelectionChanged() ) );

    MindMapView -> setScene( m_scene );

    updateActions();
}

void MainWindow::newAchivement()
{
	model::AchivementPtr ach = model -> addAchivement(tr("[no name achivement]"));
	view::Achivement* item = new view::Achivement( ach );

//	item->setRect( 0,0,100,100);
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

	view::Edge* edge = new view::Edge( m_selected_achivement, item );

	m_scene -> addItem( item );
	m_scene -> addItem( edge );

	updateActions();
}
