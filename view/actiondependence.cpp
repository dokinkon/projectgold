#include "actiondependence.h"
#include "model/basemodel.h"
#include "model/item.h"
#include "ui_actiondependence.h"
#include <QtGui>
#include <QtCore>


namespace view {

struct ActionDependence::Private : public Ui::ActionDependence
{
    QListWidget* actionList;
    QGraphicsView* workSpace;

    void createItems(const QList<model::Item*>& items)
    {
        foreach (model::Item* item, items)
        {
            if (model::Item::kAchievement==item->type()) {
                qDebug() << "create achivement item";
            } else if (model::Item::kAction==item->type()) {
                qDebug() << "create action item";
            }
        }
    }
};

ActionDependence::ActionDependence(QWidget *parent)
    : BaseView(parent)
    , m_pvt(new Private)
{
    m_pvt->setupUi(this);

    QSplitter* splitter = new QSplitter(this);
    m_pvt->actionList = new QListWidget;
    m_pvt->workSpace  = new QGraphicsView;
    splitter->addWidget(m_pvt->actionList);
    splitter->addWidget(m_pvt->workSpace);
    splitter->setOrientation(Qt::Horizontal);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(splitter);
    setLayout(layout);
}

ActionDependence::~ActionDependence()
{
    delete m_pvt;
}

void ActionDependence::refreshContentImpl(int op, const QList<model::Item*>& items)
{
    switch (op) 
    {
        case model::BaseModel::Create:
            m_pvt->createItems(items);
            break;
        case model::BaseModel::Read:
            qDebug() << "read items";
            break;
        case model::BaseModel::Update:
            qDebug() << "update items";
            break;
        case model::BaseModel::Delete:
            qDebug() << "delete items";
            break;
    }
}

} // namespace











