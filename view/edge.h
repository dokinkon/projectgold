
#ifndef _VIEW_EDGE_H_
#define _VIEW_EDGE_H_

#include <QGraphicsItem>

namespace view {
class Item;

class Edge : public QGraphicsItem
{
public:
    Edge(Item *sourceItem, Item *destItem);

    Item *sourceItem() const;
    Item *destItem() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const { return Type; }
    
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
private:
    Item *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    QPointF _controlPoint1;
    QPointF _controlPoint2;

    qreal arrowSize;
};

}

#endif
