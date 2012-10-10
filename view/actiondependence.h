#ifndef ACTIONDEPENDENCE_H
#define ACTIONDEPENDENCE_H

#include "fwdeclaration.h"
#include "view/baseview.h"

namespace view {

class ActionDependence : public BaseView
{
    Q_OBJECT
    
public:
    explicit ActionDependence(QWidget *parent = 0);
    ~ActionDependence();

private:
    void refreshContentImpl(int, const QList<model::Item*>&);
    struct Private;
    Private* m_pvt;
};

} // namespace

#endif // ACTIONDEPENDENCE_H
