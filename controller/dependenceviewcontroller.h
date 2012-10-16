#ifndef __DEPENDENCE_VIEW_CONTROLLER_H__
#define __DEPENDENCE_VIEW_CONTROLLER_H__

#include "controller/viewcontroller.h"

class DependenceViewController : public ViewController
{
    Q_OBJECT
public:
    explicit DependenceViewController(QObject* parent = 0);
    virtual ~DependenceViewController();
    void setModelAndView(model::BaseModel*, view::DependenceView*);
private:
    struct Private;
    Private* m_pvt;
private slots:
    void actionItemDroppedIntoWorkspace(const QString& uuid);
}

#endif
