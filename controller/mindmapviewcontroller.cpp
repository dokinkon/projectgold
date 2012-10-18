#include "controller/mindmapviewcontroller.h"
#include "model/basemodel.h"
#include "view/mindmapview.h"

struct MindMapViewController::Private
{
    model::BaseModel* m_model;
    view::MindMapView* m_view;

    Private()
        : m_model(NULL)
        , m_view(NULL)
    {
    }
};

MindMapViewController::MindMapViewController(QObject* parent)
    : ViewController(parent)
    , m_pvt(new Private)
{

}

MindMapViewController::~MindMapViewController()
{
    delete m_pvt;
}

void MindMapViewController::setModelAndView(model::BaseModel* model, view::MindMapView* view)
{
    m_pvt->m_model = model;
    m_pvt->m_view  = view;

    connect(model,
            SIGNAL(achievementCreated(QSharedPointer<Achievement>))
            SLOT(achievementCreated(QSharedPointer<Achievement>)));

    connect(model,
            SIGNAL(actionCreated(QSharedPointer<Action>)),
            SLOT(actionCreated(QSharedPointer<Action>)));
}

void MindMapViewController::createAchievement()
{
    m_pvt->m_model->createAchievement();
}

void MindMapViewController::createAction()
{
    const QString uuid = m_pvt->m_view->selectedAchievementItem();
    if (uuid.isEmpty())
        return;

    m_pvt->m_model->createAction(uuid);
}

void MindMapViewController::achievementCreated(QSharedPointer<Achievement> achievementPtr)
{
    m_pvt->m_view->createAchievementItem(achievementPtr->uuid(), achievementPtr->text());
    m_pvt->m_view->selectItem(achievementPtr->uuid().toString());
}

void MindMapViewController::actionCreated(QSharedPointer<Action> actionPtr)
{
    Q_ASSERT(!actionPtr.isNull());
    QWeakPointer<Achievement> achievementPtr = actionPtr->achievement();
    m_pvt->m_view->selectItem(achievementPtr->uuid().toString());
    m_pvt->m_view->createActionItem(actionPtr->uuid().toString(), actionPtr->text());
}









