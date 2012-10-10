#include "baseview.h"
#include "model/basemodel.h"

namespace view {


struct BaseView::Private
{
    model::BaseModel* model;

    Private()
        : model(NULL)
    {
    }
};

BaseView::BaseView(QWidget *parent)
    : QWidget(parent)
    , m_pvt(new Private)
{
}

BaseView::~BaseView()
{
    setModel(NULL);
    delete m_pvt;
}

void BaseView::setModel(model::BaseModel* model)
{
    if (m_pvt->model) {
        disconnect(m_pvt->model, SIGNAL(changed(int, const QList<model::Item*>&)), this, SLOT(refreshContent(int, const QList<model::Item*>&)));
    }

    m_pvt->model = model;

    if (m_pvt->model) {
        connect(m_pvt->model, SIGNAL(changed(int, const QList<model::Item*>&)), SLOT(refreshContent(int, const QList<model::Item*>&)));
    }
}

model::BaseModel* BaseView::model() const
{
    return m_pvt->model;
}
    
void BaseView::refreshContent(int op, const QList<model::Item*>& items)
{
    if (!m_pvt->model)
        return;

    refreshContentImpl(op, items);
}

void BaseView::refreshContentImpl(int, const QList<model::Item*>&)
{

}
}

