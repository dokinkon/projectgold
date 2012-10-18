#ifndef __MINDMAP_VIEW_CONTROLLER_H__
#define __MINDMAP_VIEW_CONTROLLER_H__

#include "controller/viewcontroller.h"

class MindMapViewController : public ViewController
{
    Q_OBJECT
public:
    explicit MindMapViewController(QObject* parent = 0);
    ~MindMapViewController();
    void setModelAndView(model::BaseModel*, view::MindMapView*);

public slots:
    void createAchievement();
    void createAction();

private slots:
    void achievementCreated(QSharedPointer<model::Achievement>);
    void actionCreated(QSharedPointer<model::Action>);

private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

#endif
