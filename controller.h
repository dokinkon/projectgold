#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "fwdeclaration.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();
    QGraphicsScene* mindMapScene() const;
    QGraphicsScene* actionDependenceScene() const;

    void setModel(model::BaseModel* model);
    
signals:

    void changed(int op, const QList<model::Item*>&);
    
public slots:
    void createAchievement();
    void deleteAchievement();
    void createAction();

private:
    struct Private;
    Private* m_pvt;
    
};

#endif // CONTROLLER_H
