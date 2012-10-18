#include "controller/dependenceviewcontroller.h"
#include "model/basemodel.h"
#include "model/action.h"
#include "view/actiondependenceview.h"

#include <QtGui>
#include <QtCore>

struct ActionDependenceViewController::Private
{
    model::BaseModel* m_model;
    view::ActionDependenceView* m_view;

    Private()
        : m_model(NULL)
        , m_view(NULL)
    {
    }
};

ActionDependenceViewController::ActionDependenceViewController(QObject* parent)
    : ViewController(parent)
    , m_pvt(new Private)
{

}

ActionDependenceViewController::~ActionDependenceViewController()
{
}

void ActionDependenceViewController::setModelAndView(model::BaseModel* model, view::ActionDependenceView* view)
{
    m_pvt->m_model = model;
    m_pvt->m_view  = view;

    connect(model,
            SIGNAL(actionCreated(QSharedPointer<model::Action>)),
            SLOT(createAction(QSharedPointer<model::Action>)));

    connect(model,
            SIGNAL(actionValueChanged(const QString&, int, const QVariant&)),
            view,
            SLOT(setActionValue(const QString&, int, const QVariant&)));

    connect(view->workSpaceView(),
            SIGNAL(actionItemDropped(const QString&)),
            SLOT(didDropActionItemIntoWorkspace(const QString&)));
}

void ActionDependenceViewController::createAction(QSharedPointer<model::Action> actionPtr)
{
    Q_ASSERT(!actionPtr.isNull());
    m_pvt->m_view->createActionInListView(actionPtr->uuid().toString(), actionPtr->text());
}

void ActionDependenceViewController::didDropActionItemIntoWorkspace(const QString& uuid)
{
    Q_ASSERT(m_pvt->m_view);
    qDebug() << "didDropActionItemIntoWorkspace: " << uuid;
    QSharedPointer<model::Action> actionPtr = m_pvt->m_model->action(uuid);
    Q_ASSERT(!actionPtr.isNull());

    m_pvt->m_view->createActionInWorkSpaceView(actionPtr->uuid().toString(), actionPtr->text());
}













