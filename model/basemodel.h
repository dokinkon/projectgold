#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "fwdeclaration.h"
#include <QObject>
#include <QGraphicsScene>

namespace model {

class BaseModel : public QObject
{
    Q_OBJECT
public:

    enum {
        Create,
        Read,
        Update,
        Delete
    } CRUD;


    explicit BaseModel(QObject *parent = 0);
    virtual ~BaseModel();

    QGraphicsScene* mindMapScene() const;

    AchivementPrt createAchivement();

    
signals:

    void changed(int op, const QList<model::Item*>&);
    
public slots:
    void createAchivement();
    void createAction();

private:
    struct Private;
    Private* m_pvt;
    
};

} // namespace model


#endif // BASEMODEL_H
