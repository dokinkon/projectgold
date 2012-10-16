#include "controller/dependenceviewcontroller.h"
#include "model/basemodel.h"
#include "view/dependenceview.h"

struct DependenceViewController::Private
{
    model::BaseModel* m_model;
    view::DependenceView* m_view;

    Private()
        : m_model(NULL)
        , m_view(NULL)
    {
    }
};

DependenceViewController::DependenceViewController(QObject* parent = 0)
    : ViewController(parent)
    , m_pvt(new Private)
{

}
DependenceViewController::~DependenceViewController()
{
    delete m_pvt;
}

void DependenceViewController::setModelAndView(model::BaseModel* model, view::DependenceView* view)
{
    m_pvt->m_model = model;
    m_pvt->m_view  = view;
    connect(view, SIGNAL(actionItemDroppedIntoWorkspace(const QString&)), SLOT(ationItemDroppedIntoWorkspace(const QString&)));
}

void DependenceViewController::actionItemDroppedIntoWorkspace(const QString& uuid)
{

}
