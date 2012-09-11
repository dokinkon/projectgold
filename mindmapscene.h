
#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE


class MindMapScene : public QGraphicsScene
{
    Q_OBJECT

public:
//    enum Mode { InsertItem, InsertLine, InsertText, MoveItem };

//    MindMapScene(QMenu *itemMenu, QObject *parent = 0);
      MindMapScene(QObject *parent = 0);
};


#endif
