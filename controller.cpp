#include "controller.h"
#include "model/basemodel.h"

struct Controller::Private
{
    QGraphicsScene* mindMapScene;
    QGraphicsScene* actionDependenceScene;
    model::BaseModel* model;

    Private()
        : mindMapScene(NULL)
        , actionDependenceScene(NULL)
        , model(NULL)
    {
    }
};

Controller::Controller(QObject *parent)
    : QObject(parent)
    , m_pvt(new Private)
{
    m_pvt->mindMapScene = new QGraphicsScene(this);
    m_pvt->actionDependenceScene = new QGraphicsScene(this);
}

Controller::~Controller()
{
    delete m_pvt;
}

QGraphicsScene* Controller::mindMapScene() const
{
    return m_pvt->mindMapScene;
}

QGraphicsScene* Controller::actionDependenceScene() const
{
    return m_pvt->actionDependenceScene;
}

void Controller::setModel(model::BaseModel* model)
{
    m_pvt->model = model;
}

void Controller::createArchievement()
{
	model::AchivementPtr ach = m_pvt->model->createAchivement(tr("[no name achivement]"));
    mindMapScene()->addItem(new view::Achivement(ach));
}

void Controller::deleteAchivement()
{
    view::Achivement* achivementView = m_pvt->selectedAchivementView();
    if (!achivementView)
        return;

}

void Controller::createAction()
{
    QList<QGraphicsItem*> items = mindMapScene()->selectedItems();
    if (items.isEmpty())
        return;

    QGraphicsItem* item = items.at(0);
    if (view::Item::kAchievement!=item->type())
        return;

    view::Achivement* achivementItem = qgraphicsitem_cast<view::Achivement*>(item);

	model::ActionPtr act = achivementItem->data()->addAction(tr("[no name action]"));
	view::Action* actionItem = new view::Action( act );
    actionItem->setParentItem(achivementItem);

	mindMapScene()->addItem(new view::Edge(achivementItem, actionItem));
}


