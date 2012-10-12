
#include <QtGui>
#include <QtCore>

#include "edge.h"
#include "item.h"

namespace view{

Item::Item( model::ItemPtr data )
    : QGraphicsTextItem()
    , m_data( data )
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);

    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    setTextInteractionFlags( Qt:: NoTextInteraction );

    updateView();
}

void Item::updateView()
{
    setPlainText( m_data->text() );
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
    setTextInteractionFlags( Qt:: TextEditorInteraction );
    QGraphicsTextItem::mouseDoubleClickEvent(event);
//		textCursor().selectionStart ();
//		qDebug() << "item double click\n";
}

void Item::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    QGraphicsTextItem::mousePressEvent(event);
}

void Item::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    QGraphicsTextItem::mouseReleaseEvent(event);
}
}// namespace










