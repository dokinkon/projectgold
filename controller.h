#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "fwdeclaration.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    QGraphicsScene* mindMapScene() const;
    QGraphicsScene* actionDependenceScene() const;

    void createArchievement();
    void createAction();
    
signals:
    
public slots:

private:
    struct Private;
    Private* m_pvt;
    
};

#endif // CONTROLLER_H
