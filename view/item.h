/*
 * Item.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef _VIEW_Item_H_
#define _VIEW_Item_H_

#include <QGraphicsTextItem>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <model/item.h>

namespace view {

class Edge;

class Item : public QGraphicsTextItem
{
public:
	Item( model::ItemPtr data )
		: QGraphicsTextItem()
		, m_data( data )
	{

		 setFlag(ItemIsMovable);
		 setFlag(ItemSendsGeometryChanges);
		 setFlag(ItemIsSelectable);

		 setCacheMode(DeviceCoordinateCache);
		 setZValue(-1);

//		 setTextInteractionFlags( Qt:: TextEditorInteraction );
     	setTextInteractionFlags( Qt:: NoTextInteraction );

		 updateView();
	}
	void updateView()
	{
		setPlainText( m_data->text() );
	}

	void mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * event )
	{
		setTextInteractionFlags( Qt:: TextEditorInteraction );
		QGraphicsTextItem::mouseDoubleClickEvent(event);
//		textCursor().selectionStart ();
//		qDebug() << "item double click\n";
	}
	void mousePressEvent ( QGraphicsSceneMouseEvent * event )
	{
		QGraphicsTextItem::mousePressEvent(event);
	}
	void mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
	{
		QGraphicsTextItem::mouseReleaseEvent(event);
	}

	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

	void addEdge( Edge *edge);

private:
	model::ItemPtr m_data;
    QList<Edge *> m_edges;
};

} /* namespace view */
#endif /* Item_H_ */
