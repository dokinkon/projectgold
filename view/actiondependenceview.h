#ifndef ACTIONDEPENDENCE_H
#define ACTIONDEPENDENCE_H

#include "fwdeclaration.h"
#include "view/baseview.h"
#include <QGraphicsView>
#include <QListWidget>


namespace view { namespace internal {





class WorkSpaceScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit WorkSpaceScene(QObject* parent = 0);
    ~WorkSpaceScene();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    void dropEvent(QGraphicsSceneDragDropEvent*);

private:


};


class ActionListView : public QListWidget
{
    Q_OBJECT
public:
    explicit ActionListView(QWidget* parent = 0);
    ~ActionListView();
protected:
    void startDrag(Qt::DropActions);
private:
    struct Private;
    Private* m_pvt;
};

}} // namespace view::internal


namespace view {

class WorkSpaceView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit WorkSpaceView(QWidget* parent);
    ~WorkSpaceView();
signals:
    void actionItemDropped(const QString& uuid);
protected:
    void dragEnterEvent(QDragEnterEvent*);
    void dragMoveEvent(QDragMoveEvent*);
    void dropEvent(QDropEvent*);
private:
    struct Private;
    Private* m_pvt;

};


class ActionDependenceView : public BaseView
{
    Q_OBJECT

public:
    explicit ActionDependenceView(QWidget *parent = 0);
    ~ActionDependenceView();

    WorkSpaceView* workSpaceView() const;

private:
    void refreshContentImpl(int, const QList<model::Item*>&);
    struct Private;
    Private* m_pvt;
};

} // namespace

#endif // ACTIONDEPENDENCEVIEW_H
