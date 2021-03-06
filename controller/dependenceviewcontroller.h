#ifndef __DEPENDENCE_VIEW_CONTROLLER_H__
#define __DEPENDENCE_VIEW_CONTROLLER_H__

#include "controller/viewcontroller.h"

class ActionDependenceViewController : public ViewController
{
    Q_OBJECT
public:
    explicit ActionDependenceViewController(QObject* parent = 0);
    ~ActionDependenceViewController();
    void setModelAndView(model::BaseModel*, view::ActionDependenceView*);
private:
    struct Private;
    Private* m_pvt;
private slots:
    void createAction(QSharedPointer<model::Action>);
    void didDropActionItemIntoWorkspace(const QString& uuid);
};

#endif
