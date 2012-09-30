
#include <QPainter>

#include "edge.h"
#include "item.h"

namespace view{

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
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

}
