#ifndef __MINDMAP_VIEW_CONTROLLER_H__
#define __MINDMAP_VIEW_CONTROLLER_H__

#include "controller/viewcontroller.h"

class MindMapViewController : public ViewController
{
    Q_OBJECT
public:
    explicit MindMapViewController(QObject* parent = 0);
    virtual ~MindMapViewController();
private:
    struct Private;
    Private* m_pvt;
};

#endif
