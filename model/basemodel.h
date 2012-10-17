#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "fwdeclaration.h"
#include "model/achievement.h"
#include <QObject>
#include <QGraphicsScene>
#include <QUuid>

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

    AchievementPtr createAchivement();
    ActionPtr createAction(AchievementPtr);
    ItemPtr item(const QUuid&) const;

signals:

    void changed(int op, const QList<model::Item*>&);

private:
    struct Private;
    Private* m_pvt;

};

} // namespace model


#endif // BASEMODEL_H
