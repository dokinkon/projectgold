/*
 * mindmapview.h
 *
 *  Created on: 2012/9/11
 *      Author: chaochih.lin
 */

#ifndef __MIND_MAP_VIEW__
#define __MIND_MAP_VIEW__

#include <QGraphicsTextItem>
#include "fwdeclaration.h"

class QGraphicsSceneMouseEvent;


namespace view { namespace mindmap {

class Item;

enum {
    EdgeType = QGraphicsItem::UserType + 1,
    AchievementType,
    ActionType
};


class Edge : public QGraphicsItem
{
public:
    Edge(Item *sourceItem, Item *destItem);

    Item *sourceItem() const;
    Item *destItem() const;

    void adjust();

    int type() const { return EdgeType; }

protected:
    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:
    Item *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    QPointF _controlPoint1;
    QPointF _controlPoint2;

    qreal arrowSize;
};

class Item : public QGraphicsTextItem
{
public:

    Item( model::ItemPtr data );
    void updateView();
    void addEdge( Edge *edge);
    QRectF boundingRect() const;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:
    model::ItemPtr m_data;
    QList<Edge *> m_edges;
};

class Achievement : public Item
{
public:
    Achievement(model::AchievementPtr data);
    model::AchievementPtr data() const;
    int type() const { return AchievementType; }

private:
    model::AchievementPtr	m_achievement_data;
};

class Action : public Item
{
public:
    Action(model::ActionPtr data);
    model::ActionPtr data() const;
    int type() const { return ActionType; }
private:
    model::ActionPtr p_action_data;
};

}} // namespace view::mindmap
#endif // Header Guard
