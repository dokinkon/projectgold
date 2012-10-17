#ifndef __MINDMAP_VIEW_H__
#define __MINDMAP_VIEW_H__

#include <QWidget>
#include <QSharedPointer>

namespace view { namespace internal {


}} // namespace view::internal

namespace view {

class MindMapView : public QWidget
{
    Q_OBJECT
public:
    explicit MindMapView(QWidget* parent = 0);
    ~MindMapView();
    bool selectItem(const QString& uuid);
    bool createAchievementItem(const QString& uuid, const QString& text);
    bool createActionItem(const QString& uuid, const QString& text);
protected:
    // check data consistance
    void timerEvent(QTimerEvent*);
private:
    struct Private;
    QSharedPointer<Private> m_pvt;
};

} // namespace view

#endif
