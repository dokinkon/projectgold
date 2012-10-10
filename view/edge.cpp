
#include <QPainter>

#include "edge.h"
#include "item.h"

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

namespace view{


Edge::Edge(Item *sourceItem, Item *destItem)
    : arrowSize(10)
{
    setAcceptedMouseButtons(0);
    source = sourceItem;
    dest = destItem;
    source->addEdge(this);
    dest->addEdge(this);
    setZValue(-2);
    adjust();
}

Item *Edge::sourceItem() const
{
    return source;
}

Item *Edge::destItem() const
{
    return dest;
}

void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }

    sourcePoint = source->scenePos() + QPointF(source->boundingRect().width()/2, source->boundingRect().height()/2);
    destPoint   = dest->scenePos()   + QPointF(dest->boundingRect().width()/2, dest->boundingRect().height()/2);

    const int x = sourcePoint.x() * .75f + destPoint.x() * .25f;

    _controlPoint1.setX(x);
    _controlPoint1.setY(destPoint.y());

    _controlPoint2.setX(x);
    _controlPoint2.setY(destPoint.y());
}

QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    painter->setPen(QPen(QColor(128, 128, 128), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    //painter->drawLine(line);

    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * arrowSize,
                                                  cos(angle + Pi / 3) * arrowSize);
    QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                                  cos(angle + Pi - Pi / 3) * arrowSize);   
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);

    painter->setBrush(QBrush(QColor(0, 0, 0, 0)));
    QPainterPath path;
    path.moveTo(sourcePoint);
    path.cubicTo(_controlPoint1, _controlPoint2, destPoint);
    //path.cubicTo(_controlPoint2, _controlPoint1, sourcePoint);


    painter->drawPath(path);
    
    //painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    //painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
}


}
