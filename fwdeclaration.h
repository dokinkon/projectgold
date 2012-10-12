#ifndef FWDECLARATION_H
#define FWDECLARATION_H

#include "global.h"

//QT_BEGIN_NAMESPACE
class QMenu;
class QPointF;
class QFont;
class QColor;
class QGraphicsLineItem;
class QGraphicsTextItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
//QT_END_NAMESPACE



namespace model {

class BaseModel;
class Item;
class Achievement;
class Action;

typedef SHARED_PTR(Item) ItemPtr;
typedef SHARED_PTR(Achievement) AchievementPtr;
typedef SHARED_PTR(Action) ActionPtr;

} // namespace model


namespace view {


class BaseView;

} // namespace view

#endif // FWDECLARATION_H
