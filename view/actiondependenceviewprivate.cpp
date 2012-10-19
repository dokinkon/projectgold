#include "view/actiondependenceviewprivate.h"
#include <QtCore>
#include <QtGui>

namespace view { namespace adv { namespace pvt {

Edeg::Edeg(QGraphicsItem* parent = 0)
    : QGraphicsLineItem(parent)
{
}

ActionItem* Edge::sourceItem() const
{
    return m_source;
}

void Edge::setDestinationPosition(const QPointF& position)
{
    m_destinationPosition = position;
    adjust();
}

void Edge::setDestinationItem(ActionItem* actionItem)
{
    m_destination = actionItem;
    adjust();
}

ActionItem* Edge::destinationItem() const
{
    return m_destination;
}

void Edge::adjust() 
{
    if (!m_source)
        return;

    QPointF sourcePosition = m_source->scenePos();

    if (m_destination) {
        m_destinationPosition = m_destination->scenePos();
    }

    setLine(QLineF(sourcePosition, m_destinationPosition));
}


ActionItem::ActionItem(QGraphicsItem* parent = 0)
    : QGraphicsSimpleTextItem(parent)
{
}

void ActionItem::addOutgoingEdge(Edge* edge)
{
    if (!edge || m_outgoingEdges.contains(edge))
        return;

    m_outgoingEdges << edge;
}

void ActionItem::removeOutgoingEdge(Edge* edge)
{
    m_outgoingEdges.removeAll(edge);
    if (edge) {
        edge->setSourceItem(NULL);
    }
}

void ActionItem::addIncomingEdge(Edge* edge)
{
    if (!edge || m_incomingEdges.contains(edge))
        return;

    m_incomingEdges << edge;
}

void ActionItem::removeIncomingEdge(Edge* edge)
{
    m_incomingEdges.removeAll(edge);
}

WorkSpaceScene::WorkSpaceScene(QObject* parent = 0)
    : QGraphicsScene(parent)
{
}

void WorkSpaceScene::mousePressEvent(QGraphicsSceneMouseEvent* ev)
{
    Qt::KeyboardModifiers modifiers = ev->modifiers();
    ActionItem* item = dynamic_cast<ActionItem*>(itemAt(ev->scenePos()));
    if (item && modifiers & Qt::ControlModifier && Qt::LeftButton == ev->button()) {
        Q_ASSERT(!m_currentEdge);
        m_currentEdge = new Edge(item, NULL);
        addItem(m_currentEdge);
    } else {
        QGraphicsScene::mousePressEvent(ev);
    }
}

void WorkSpaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent* ev)
{
    if (m_currentEdge) {
        m_currentEdge->setDestinationPosition(ev->scenePos());
    } else {
        QGraphicsScene::mouseMoveEvent(ev);
    }
}

void WorkSpaceScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* ev)
{
    if (m_currentEdge) {
        ActionItem* actionItem = dynamic_cast<ActionItem*>(itemAt(ev->scenePos()));
        if (actionItem && actionItem != m_currentEdge->sourceItem()) {
            m_currentEdge->setDestinationItem(actionItem);
            emit actionItemHasConnected(m_currentEdge->sourceItem()->uuid(), m_currentEdge->destinationItem()->uuid());
        } else {
            removeItem(m_currentEdge);
            delete m_currentEdge;
        }
        m_currentEdge = NULL;
    } else {
        QGraphicsScene::mouseReleaseEvent(ev);
    }
}

}}} // namespace view::adv::pvt
