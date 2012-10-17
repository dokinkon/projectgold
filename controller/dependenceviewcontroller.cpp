#include "controller/dependenceviewcontroller.h"
#include "model/basemodel.h"
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
    delete m_pvt;
}

void ActionDependenceViewController::setModelAndView(model::BaseModel* model, view::ActionDependenceView* view)
{
    m_pvt->m_model = model;
    m_pvt->m_view  = view;
    connect(view->workSpaceView(),
            SIGNAL(actionItemDropped(const QString&)),
            SLOT(didDropActionItemIntoWorkspace(const QString&)));
}

void ActionDependenceViewController::didDropActionItemIntoWorkspace(const QString& uuid)
{
    Q_ASSERT(m_pvt->m_view);
    qDebug() << "didDropActionItemIntoWorkspace: " << uuid;

}
