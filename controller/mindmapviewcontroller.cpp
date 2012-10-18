#include "controller/mindmapviewcontroller.h"
#include "model/basemodel.h"
#include "model/action.h"
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
}

void MindMapViewController::setModelAndView(model::BaseModel* model, view::MindMapView* view)
{
    m_pvt->m_model = model;
    m_pvt->m_view  = view;

    connect(model,
            SIGNAL(achievementCreated(QSharedPointer<model::Achievement>)),
            SLOT(achievementCreated(QSharedPointer<model::Achievement>)));

    connect(model,
            SIGNAL(actionCreated(QSharedPointer<model::Action>)),
            SLOT(actionCreated(QSharedPointer<model::Action>)));

    connect(view,
            SIGNAL(achievementValueChanged(const QString&, int, const QVariant&)),
            model,
            SLOT(setAchievementValue(const QString&, int, const QVariant&)));

    connect(view,
            SIGNAL(actionValueChanged(const QString&, int, const QVariant&)),
            model,
            SLOT(setActionValue(const QString&, int, const QVariant&)));
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

void MindMapViewController::achievementCreated(QSharedPointer<model::Achievement> achievementPtr)
{
    m_pvt->m_view->createAchievementItem(achievementPtr->uuid(), achievementPtr->text());
    m_pvt->m_view->selectItem(achievementPtr->uuid().toString());
}

void MindMapViewController::actionCreated(QSharedPointer<model::Action> actionPtr)
{
    Q_ASSERT(!actionPtr.isNull());
    QSharedPointer<model::Achievement> achievementPtr = actionPtr->achievement().toStrongRef();
    Q_ASSERT(!achievementPtr.isNull());
    m_pvt->m_view->selectItem(achievementPtr->uuid().toString());
    m_pvt->m_view->createActionItem(actionPtr->uuid().toString(), actionPtr->text());
}









