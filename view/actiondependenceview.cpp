#include "actiondependenceview.h"
#include "model/basemodel.h"
#include "model/item.h"
#include "model/action.h"
#include "ui_actiondependence.h"
#include <QtGui>
#include <QtCore>

namespace view { namespace internal {





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
    mimeData->setData(QLatin1String("item/uuid"), item->data(RoleUuid).toString().toLatin1().data());
    mimeData->setText(item->text());
    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec();
}

}} // namespace view::internal


namespace view {

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
    QGraphicsView::dragEnterEvent(e);
}

void WorkSpaceView::dropEvent(QDropEvent* e)
{
    //qDebug() << "WorkSpaceView::dropEvent:" << e->mimeData()->text();
    QGraphicsView::dropEvent(e);
    const QString uuid = QString::fromLatin1(e->mimeData()->data(QLatin1String("item/uuid")).data());
    emit actionItemDropped(uuid);
}

void WorkSpaceView::dragMoveEvent(QDragMoveEvent* e)
{
    e->acceptProposedAction();
}

struct ActionDependenceView::Private : public Ui::ActionDependence
{
    internal::ActionListView* m_actionListView;
    WorkSpaceView* m_workSpaceView;
    QGraphicsScene* m_workSpaceScene;

    Private()
        : m_actionListView(NULL)
        , m_workSpaceView(NULL)
        , m_workSpaceScene(NULL)
    {
    }

    QListWidgetItem* actionInListView(const QUuid& uuid)
    {
        // TODO
        return NULL;
    }

    QGraphicsSimpleTextItem* actionInWorkSpaceView(const QUuid& uuid)
    {
        // TODO
        return NULL;
    }

};

ActionDependenceView::ActionDependenceView(QWidget *parent)
    : BaseView(parent)
    , m_pvt(new Private)
{
    m_pvt->setupUi(this);

    QSplitter* splitter = new QSplitter(this);
    m_pvt->m_actionListView = new internal::ActionListView(this);
    m_pvt->m_actionListView->setDragDropMode(QAbstractItemView::DragOnly);
    splitter->addWidget(m_pvt->m_actionListView);

    m_pvt->m_workSpaceView  = new WorkSpaceView(this);
    m_pvt->m_workSpaceScene = new QGraphicsScene(this);
    m_pvt->m_workSpaceView->setScene(m_pvt->m_workSpaceScene);
    splitter->addWidget(m_pvt->m_workSpaceView);

    splitter->setOrientation(Qt::Horizontal);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(splitter);
    setLayout(layout);
}

ActionDependenceView::~ActionDependenceView()
{
}

void ActionDependenceView::createActionInListView(const QString& uuid, const QString& text)
{
    QListWidgetItem* item = new QListWidgetItem(text);
    item->setData(RoleUuid, uuid);
    m_pvt->m_actionListView->addItem(item);
}

void ActionDependenceView::createActionInWorkSpaceView(const QString& uuid, const QString& text)
{
    QGraphicsSimpleTextItem* item = new QGraphicsSimpleTextItem(text);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    item->setData(RoleUuid, uuid);
    m_pvt->m_workSpaceScene->addItem(item);
}

void ActionDependenceView::setActionValue(const QString& uuid, int role, const QVariant& value)
{
    for (int i=0;i<m_pvt->m_actionListView->count();++i)
    {
        QListWidgetItem* item = m_pvt->m_actionListView->item(i);
        if (item->data(RoleUuid).toString()==uuid) {
            item->setText(value.toString());
            break;
        }
    }

    foreach (QGraphicsItem* baseItem, m_pvt->m_workSpaceScene->items())
    {
        if (baseItem->data(RoleUuid).toString()==uuid) {
            QGraphicsSimpleTextItem* item = dynamic_cast<QGraphicsSimpleTextItem*>(baseItem);
            item->setText(value.toString());
            break;
        }
    }
}

WorkSpaceView* ActionDependenceView::workSpaceView() const
{
    return m_pvt->m_workSpaceView;
}

} // namespace











