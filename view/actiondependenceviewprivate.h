#ifndef __ACTION_DEPENDENCE_VIEW_PRIVATE_H__
#define __ACTION_DEPENDENCE_VIEW_PRIVATE_H__

#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>

namespace view { namespace adv { namespace pvt {

class ActionItem;

class Edge : public QGraphicsLineItem
{
public:
    explicit Edeg(QGraphicsItem* parent = 0);
    ActionItem* sourceItem() const;
    void setDestinationPosition(const QPointF& position);
    void setDestinationItem(ActionItem* actionItem);
    ActionItem* destinationItem() const;
    void adjust() ;

private:
    ActionItem* m_source;
    ActionItem* m_destination;
    QPointF m_destinationPosition;
};

class ActionItem : public QGraphicsSimpleTextItem
{
public:
    explicit ActionItem(QGraphicsItem* parent = 0);
    void addOutgoingEdge(Edge* edge);
    void removeOutgoingEdge(Edge* edge);

    void addIncomingEdge(Edge* edge);
    void removeIncomingEdge(Edge* edge);

private:
    QList<Edeg*> m_outgoingEdges;
    QList<Edge*> m_incomingEdges;
};

class WorkSpaceScene : public QGraphicsScene
{
public:
    WorkSpaceScene(QObject* parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* ev);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* ev);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* ev);
};

}}} // namespace view::adv::pvt

#endif
