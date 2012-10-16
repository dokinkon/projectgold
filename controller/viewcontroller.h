#ifndef __VIEW_CONTROLLER_H__
#define __VIEW_CONTROLLER_H__

#include <QObject>

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
