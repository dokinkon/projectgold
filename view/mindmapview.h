#ifndef __MINDMAP_VIEW_H__
#define __MINDMAP_VIEW_H__

#include <QWidget>
#include <QScopedPointer>

namespace view {

class MindMapView : public QWidget
{
    Q_OBJECT
public:
    explicit MindMapView(QWidget* parent = 0);
    ~MindMapView();
    bool createAchievementItem(const QString& uuid, const QString& text);
    bool createActionItem(const QString& uuid, const QString& text);

    bool selectItem(const QString& uuid);
    QString selectedAchievementItem() const;
    QString selectedActionItem() const;
    
signals:
    void achievementValueChanged(const QString& uuid, int role, const QVariant&);
    void actionValueChanged(const QString& uuid, int role, const QVariant&);
protected:
    // check data consistance
    void timerEvent(QTimerEvent*);
private:
    struct Private;
    QSharedPointer<Private> m_pvt;
};

} // namespace view

#endif
