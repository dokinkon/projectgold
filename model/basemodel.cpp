#include "basemodel.h"
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

// will move to controller
AchievementPtr BaseModel::createAchivement()
{
    return m_pvt->root.addAchivement(tr("[no name achivement]"));
    //emit changed(Create, QList<Item*>() << ptr.get());
}

// will move to controller
void BaseModel::createAction()
{
    /*
    QList<QGraphicsItem*> items = m_pvt->mindMapScene->selectedItems();
    if (items.isEmpty())
        return;

    QGraphicsItem* item = items.at(0);
    if (view::Item::kAchievement!=item->type())
        return;

    view::Achivement* achivement = qgraphicsitem_cast<view::Achivement*>( item );

    model::ActionPtr act = m_selected_achivement -> data()-> addAction(tr("[no name action]"));
    view::Action* item = new view::Action( act );
    item->setParentItem(m_selected_achivement);

    view::Edge* edge = new view::Edge( m_selected_achivement, item );

    //m_scene -> addItem( item );
    m_scene -> addItem( edge );
    */


}

} // namespace model














