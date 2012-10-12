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
    enum {
        kAchievement = UserType + 5,
        kAction
    } Type;

    Item( model::ItemPtr data );
    void updateView();
    void addEdge( Edge *edge);
    QRectF boundingRect() const;

protected:
    void mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * );
    void mousePressEvent ( QGraphicsSceneMouseEvent * );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * );
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void paint(QPainter*, const QStyleOptionGraphicsItem * option, QWidget * widget);

private:
    model::ItemPtr m_data;
    QList<Edge *> m_edges;
};

} /* namespace view */
#endif /* Item_H_ */
