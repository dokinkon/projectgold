
#include <QtGui>

#include "mainwindow.h"
#include "mindmapscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
	, m_scene( new MindMapScene(this) )
{
    setupUi(this);

    model = model::RootPtr( new model::Root() );

    connect( newAchivementAction, SIGNAL(triggered()), this, SLOT(newAchivement()) );

    MindMapView -> setScene( m_scene );

}

void MainWindow::newAchivement()
{
	qDebug(" hello \n");
	QGraphicsRectItem* item = model -> addAchivement("[no name]");

	item->setRect( 0,0,100,100);
	m_scene -> addItem( item );
}
