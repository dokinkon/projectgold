#ifndef BASEVIEW_H
#define BASEVIEW_H

#include "fwdeclaration.h"
#include <QWidget>
#include <QScopedPointer>

namespace view {

enum DataRole {
    RoleUuid = 65535,
    RoleDisplayText,
    RoleIcon,
    RoleColor
};

class BaseView : public QWidget
{
    Q_OBJECT
public:
    explicit BaseView(QWidget *parent = 0);
    virtual ~BaseView();
    
private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

} // namespace


#endif // BASEVIEW_H
