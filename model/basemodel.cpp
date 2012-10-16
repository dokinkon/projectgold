#include "basemodel.h"
#include "model/action.h"
#include "root.h"


namespace model {

struct BaseModel::Private
{
    Root root;
    QGraphicsScene* mindMapScene;

    Private()
        : mindMapScene(NULL)
    {
    }
};

BaseModel::BaseModel(QObject *parent)
    : QObject(parent)
    , m_pvt(new Private)
{
    m_pvt->mindMapScene = new QGraphicsScene(this);
}

BaseModel::~BaseModel()
{
    delete m_pvt;
}

QGraphicsScene* BaseModel::mindMapScene() const
{
    return m_pvt->mindMapScene;
}

AchievementPtr BaseModel::createAchivement()
{
    AchievementPtr achivementPtr = m_pvt->root.addAchivement(tr("no name achievement"));
    emit changed(Create, QList<Item*>() << achivementPtr.get());
    return achivementPtr;
}

ActionPtr BaseModel::createAction(AchievementPtr achivementPtr)
{
    ActionPtr actionPtr = achivementPtr->addAction(tr("no name action"));
    emit changed(Create, QList<Item*>() << static_cast<model::Item*>(actionPtr.get()));
    return actionPtr;
}

} // namespace model














