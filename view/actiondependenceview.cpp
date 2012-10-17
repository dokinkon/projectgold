#include "actiondependenceview.h"
#include "model/basemodel.h"
#include "model/item.h"
#include "model/action.h"
#include "ui_actiondependence.h"
#include <QtGui>
#include <QtCore>


namespace view { namespace internal {





WorkSpaceScene::WorkSpaceScene(QObject* parent)
    : QGraphicsScene(parent)
{

}

WorkSpaceScene::~WorkSpaceScene()
{

}

void WorkSpaceScene::dragEnterEvent(QGraphicsSceneDragDropEvent* e)
{
    QGraphicsScene::dragEnterEvent(e);
}

void WorkSpaceScene::dropEvent(QGraphicsSceneDragDropEvent* e)
{
    QGraphicsScene::dropEvent(e);
    //qDebug() << "dropEvent";
    //QGraphicsTextItem* item = new QGraphicsTextItem;
    //item->setPlainText(e->mimeData()->text());
    //item->setPos(e->scenePos());
    //addItem(item);
}




struct ActionListView::Private
{

};

ActionListView::ActionListView(QWidget* parent)
    : QListWidget(parent)
    , m_pvt(new Private)
{
}

ActionListView::~ActionListView()
{
    delete m_pvt;
}

// http://qt-project.org/forums/viewthread/12997
void ActionListView::startDrag(Qt::DropActions)
{
    QListWidgetItem* item = currentItem();
    QMimeData* mimeData = new QMimeData;
    //QByteArray ba = item->text().toLatin1().data();
    mimeData->setData(QLatin1String("item/uuid"), item->data(33).toString().toLatin1().data());
    mimeData->setText(item->text());
    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec();
}

}} // namespace view::internal


namespace view {

const static int UuidRole = Qt::UserRole + 5;

struct WorkSpaceView::Private
{

};

WorkSpaceView::WorkSpaceView(QWidget* parent)
    : QGraphicsView(parent)
    , m_pvt(new Private)
{
    setAcceptDrops(true);
}

WorkSpaceView::~WorkSpaceView()
{
    delete m_pvt;
}

void WorkSpaceView::dragEnterEvent(QDragEnterEvent* e)
{
    //qDebug() << "WorkSpaceView::dragEnterEvent:" << e->mimeData()->text();
    QGraphicsView::dragEnterEvent(e);
    //e->acceptProposedAction();
}

void WorkSpaceView::dropEvent(QDropEvent* e)
{
    //qDebug() << "WorkSpaceView::dropEvent:" << e->mimeData()->text();
    QGraphicsView::dropEvent(e);
    emit actionItemDropped(e->mimeData()->text());
}

void WorkSpaceView::dragMoveEvent(QDragMoveEvent* e)
{
    //qDebug() << "WorkSpaceView::dragMoveEvent:" << e->mimeData()->text();
    e->acceptProposedAction();
}
struct ActionDependenceView::Private : public Ui::ActionDependence
{
    internal::ActionListView* actionList;
    WorkSpaceView* workSpace;

    QListWidgetItem* actionInListView(const QUuid& uuid)
    {
        for (int row=0;row<actionList->count();++row)
        {
            QListWidgetItem* item = actionList->item(row);
            return item;
            //if (item->data(UuidRole).value<QUuid>()==uuid) {
                //return item;
            //}
        }
        return NULL;
    }

    QGraphicsSimpleTextItem* actionInWorkSpaceView(const QUuid& uuid)
    {
        //foreach (QGraphicsItem* item, workSpace->items())
        //{
            //if (item->data(UuidRole).value<QUuid>()==uuid) {
              //  return dynamic_cast<QGraphicsSimpleTextItem*>(item);
            //}
        //}
        return NULL;
    }

    void createItems(const QList<model::Item*>& items)
    {
        foreach (model::Item* modelItem, items)
        {
            if (model::AchievementType==modelItem->type()) {
                qDebug() << "create achivement item";
            } else if (model::ActionType==modelItem->type()) {
                qDebug() << "create action item";
                QListWidgetItem* viewItem = new QListWidgetItem(modelItem->text());
                //viewItem->setData(UuidRole, modelItem->uuid());
                actionList->addItem(viewItem);
            }
        }
    }

    void updateItems(const QList<model::Item*>& items)
    {
        foreach (model::Item* modelItem, items)
        {
            QListWidgetItem* actionItem = actionInListView(modelItem->uuid());
            if (actionItem) {
                actionItem->setText(modelItem->text());
            }

            QGraphicsSimpleTextItem* actionItem2 = actionInWorkSpaceView(modelItem->uuid());
            if (actionItem2) {
                actionItem2->setText(modelItem->text());
            }
        }
    }
};

ActionDependenceView::ActionDependenceView(QWidget *parent)
    : BaseView(parent)
    , m_pvt(new Private)
{
    m_pvt->setupUi(this);

    QSplitter* splitter = new QSplitter(this);
    m_pvt->actionList = new internal::ActionListView(this);
    m_pvt->actionList->setDragDropMode(QAbstractItemView::DragOnly);
    splitter->addWidget(m_pvt->actionList);

    m_pvt->workSpace  = new WorkSpaceView(this);
    internal::WorkSpaceScene* workSpaceScene = new internal::WorkSpaceScene(this);
    m_pvt->workSpace->setScene(workSpaceScene);
    splitter->addWidget(m_pvt->workSpace);

    splitter->setOrientation(Qt::Horizontal);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(splitter);
    setLayout(layout);
}

ActionDependenceView::~ActionDependenceView()
{
    delete m_pvt;
}

WorkSpaceView* ActionDependenceView::workSpaceView() const
{
    return m_pvt->workSpace;
}

void ActionDependenceView::refreshContentImpl(int op, const QList<model::Item*>& items)
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
            m_pvt->updateItems(items);
            break;
        case model::BaseModel::Delete:
            qDebug() << "delete items";
            break;
    }
}

} // namespace











