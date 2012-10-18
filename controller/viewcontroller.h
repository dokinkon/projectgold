#ifndef __VIEW_CONTROLLER_H__
#define __VIEW_CONTROLLER_H__

#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>
#include "fwdeclaration.h"

class ViewController : public QObject
{
    Q_OBJECT
public:
    explicit ViewController(QObject* parent);
    virtual ~ViewController();
private:
    struct Private;
    Private* m_pvt;
};

#endif
