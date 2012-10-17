#include "mindmapview.h"
#include <QtCore>
#include <QtGui>

namespace view { namespace internal {

class Edge : public QGraphicsItem
{
public:
    Edge(Item *sourceItem, Item *destItem)
    {
        setAcceptedMouseButtons(0);
        m_source = sourceItem;
        m_dest = destItem;
        m_source->addEdge(this);
        m_dest->addEdge(this);
        setZValue(-2);
        adjust();
    }

    Item *sourceItem() const
    {
        return m_source;
    }

    Item *destItem() const
    {
        return m_dest;
    }

    void adjust()
    {
        if (!m_source||!m_dest)
            return;

        QLineF line(mapFromItem(m_source, 0, 0), mapFromItem(m_dest, 0, 0));
        qreal length = line.length();

        prepareGeometryChange();

        if (length > qreal(20.)) {
            QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
            m_sourcePoint = line.p1() + edgeOffset;
            m_destPoint = line.p2() - edgeOffset;
        } else {
            m_sourcePoint = m_destPoint = line.p1();
        }

        m_sourcePoint = m_source->scenePos() + QPointF(m_source->boundingRect().width()/2, m_source->boundingRect().height()/2);
        m_destPoint   = m_dest->scenePos()   + QPointF(m_dest->boundingRect().width()/2, m_dest->boundingRect().height()/2);

        const int x = m_sourcePoint.x() * .75f + m_destPoint.x() * .25f;

        m_controlPoint1.setX(x);
        m_controlPoint1.setY(destPoint.y());

        m_controlPoint2.setX(x);
        m_controlPoint2.setY(destPoint.y());
    }

    int type() const { return EdgeType; }

protected:
    QRectF boundingRect() const
    {
        if (!m_source || !m_dest)
            return QRectF();

        qreal penWidth = 1;
        qreal extra = (penWidth + arrowSize) / 2.0;

        return QRectF(m_sourcePoint, QSizeF(m_destPoint.x() - m_sourcePoint.x(),
                    m_destPoint.y() - m_sourcePoint.y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
    }

    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
    {
        if (!m_source || !m_dest)
            return;

        QLineF line(sourcePoint, destPoint);
        if (qFuzzyCompare(line.length(), qreal(0.)))
            return;

        painter->setPen(QPen(QColor(128, 128, 128), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(QBrush(QColor(0, 0, 0, 0)));
        QPainterPath path;
        path.moveTo(m_sourcePoint);
        path.cubicTo(m_controlPoint1, m_controlPoint2, m_destPoint);
        painter->drawPath(path);
    }

private:
    Item *m_source, *m_dest;
    QPointF m_sourcePoint;
    QPointF m_destPoint;
    QPointF m_controlPoint1;
    QPointF m_controlPoint2;

    qreal arrowSize;
};

class Item : public QGraphicsTextItem
{
public:
    Item(QGraphicsItem* parent = 0)
        : QGraphicsTextItem(parent)
    {
    }
    void addEdge(Edge *edge)
    {
        m_edges << edge;
        edge->adjust();
    }
    QRectF boundingRect() const
    {
        QRectF bound = QGraphicsTextItem::boundingRect();
        bound.adjust(-10, -10, 10, 10);
        return bound;
    }

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* ev)
    {
        setTextInteractionFlags(Qt::TextEditorInteraction);
        QGraphicsTextItem::mouseDoubleClickEvent(ev);
    }

    QVariant itemChange(GraphicsItemChange change, const QVariant &value)
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

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* style, QWidget* widget)
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

private:
    QList<Edge *> m_edges;
};

class WorkSpaceScene : public QGraphicsScene
{
public:
    WorkSpaceScene(QObject* parent = 0)
        : QGraphicsScene(parent)
    {
    }

    QMap<QString, QString> changedItems() const
    {
        QMap<QString, QString> changed;
        return changed;
    }
};

}}

namespace view {

struct MindMapView::Private
{
    internal::WorkSpaceScene* m_workSpaceScene;

    Private()
        : m_workSpaceScene(NULL)
    {
    }

};

MindMapView::MindMapView(QWidget* parent)
    : QWidget(parent)
    , m_pvt(new Private)
{
    m_pvt->m_workSpaceScene = new internal::WorkSpaceScene(this);
    startTimer(200);
}

MindMapView::~MindMapView()
{
}

bool MindMapView::selectItem(const QString& uuid)
{
    return false;
}

bool MindMapView::createAchievementItem(const QString& uuid, const QString& text)
{
    internal::AchievementItem* item = new internal::AchievementItem;
    item->setData(KeyUuid, uuid);
    item->setData(KeyDisplayText, text);
    item->setPlainText(text);
    m_pvt->m_workSpaceScene->addItem(item);
    return false;
}

bool MindMapView::createActionItem(const QString& uuid, const QString& text)
{
    internal::ActionItem* item = new internal::ActionItem;
    item->setData(KeyUuid, uuid);
    item->setData(KeyDisplayText, text);
    item->setPlainText(text);
    item->setPlainText(text);
    m_pvt->m_workSpaceScene->addItem(item);
    return false;
}

void MindMapView::timerEvent(QTimerEvent* ev)
{
    QMap<QString, QString> changedItems = m_pvt->changedItems();
    if (changedItems.isEmpty())
        return;



}

} // namespace view
