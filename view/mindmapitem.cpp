#include "mindmapitem.h"
#include "model/achievement.h"
#include "model/action.h"

#include <QtGui>
#include <QtCore>
#include <math.h>

namespace view { namespace mindmap {


//static const double Pi = 3.14159265358979323846264338327950288419717;
//static double TwoPi = 2.0 * Pi;



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
    painter->setBrush(QBrush(QColor(0, 0, 0, 0)));
    QPainterPath path;
    path.moveTo(sourcePoint);
    path.cubicTo(_controlPoint1, _controlPoint2, destPoint);
    painter->drawPath(path);
}

Item::Item(model::ItemPtr data)
    : QGraphicsTextItem()
    , m_data( data )
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);

    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    setTextInteractionFlags(Qt::NoTextInteraction);
    updateView();
}

void Item::updateView()
{
    setPlainText(m_data->text());
}

void Item::addEdge( Edge *edge)
{
    m_edges << edge;
    edge->adjust();
}

QVariant Item::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, m_edges)
            edge->adjust();
        break;
    case ItemSelectedHasChanged:
        // Disable multiselection
        if (isSelected()) {
            foreach (QGraphicsItem* item, scene()->items())
            {
                if (item!=this)
                    item->setSelected(false);
            }
        } else {
            setTextInteractionFlags(Qt::NoTextInteraction);
        }
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

QRectF Item::boundingRect() const
{
    QRectF bound = QGraphicsTextItem::boundingRect();
    bound.adjust(-10, -10, 10, 10);
    return bound;
}

void Item::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->save();
    QRectF bound = boundingRect();
    bound.adjust(5, 5, -5, -5);
    QPen pen(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->setBrush(QBrush(QColor(100, 100, 255)));
    painter->drawRoundedRect(bound, 20, bound.height());
    painter->restore();
    setDefaultTextColor(Qt::white);
    QGraphicsTextItem::paint(painter, option, widget);
}

void Item::mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * event )
{
    setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

void Item::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    QGraphicsTextItem::mousePressEvent(event);
}

void Item::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    QGraphicsTextItem::mouseReleaseEvent(event);
}

Achievement::Achievement(model::AchievementPtr data)
    : Item(data)
{
    m_achievement_data = data;
}

model::AchievementPtr Achievement::data() const
{
    return m_achievement_data;
}

Action::Action(model::ActionPtr data)
    : Item(data)
{
    p_action_data = data;
}

model::ActionPtr Action::data() const
{
    return p_action_data;
}

}} // namespace view::mindmap
