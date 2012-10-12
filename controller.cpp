#include "controller.h"
#include "model/basemodel.h"
#include "view/achievement.h"
#include "view/action.h"
#include "view/edge.h"
#include <QtCore>
#include <QtGui>

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

void Controller::createAchievement()
{
    model::AchievementPtr ach = m_pvt->model->createAchivement();
    mindMapScene()->addItem(new view::Achievement(ach));
}

void Controller::deleteAchievement()
{
    //view::Achievement* achivementView = m_pvt->selectedAchivementView();
    //if (!achivementView)
        //return;
}

void Controller::createAction()
{
    QList<QGraphicsItem*> items = mindMapScene()->selectedItems();
    if (items.isEmpty())
        return;

    QGraphicsItem* item = items.at(0);
    if (view::Item::kAchievement!=item->type())
        return;

    view::Achievement* achievementItem = qgraphicsitem_cast<view::Achievement*>(item);

    model::ActionPtr act = achievementItem->data()->addAction(tr("[no name action]"));
	view::Action* actionItem = new view::Action( act );
    actionItem->setParentItem(achievementItem);

    mindMapScene()->addItem(new view::Edge(achievementItem, actionItem));
}


