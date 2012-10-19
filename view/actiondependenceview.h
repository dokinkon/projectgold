#ifndef ACTIONDEPENDENCE_H
#define ACTIONDEPENDENCE_H

#include "fwdeclaration.h"
#include "view/baseview.h"
#include <QGraphicsView>
#include <QListWidget>


namespace view { namespace internal {


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

    void createActionInListView(const QString& uuid, const QString& text);
    void createActionInWorkSpaceView(const QString& uuid, const QString& text);

    WorkSpaceView* workSpaceView() const;

signals:
    void actionItemHasConnected(const QString& sourceUuid, const QString& destUuid);

public slots:
    void setActionValue(const QString& uuid, int role, const QVariant& value);

private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

} // namespace

#endif // ACTIONDEPENDENCEVIEW_H
