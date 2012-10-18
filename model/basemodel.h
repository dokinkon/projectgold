#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "fwdeclaration.h"
#include "model/achievement.h"
#include <QObject>
#include <QGraphicsScene>
#include <QUuid>
#include <QSharedPointer>
#include <QScopedPointer>

namespace model {

class BaseModel : public QObject
{
    Q_OBJECT
public:
    enum CURD {
        Create,
        Read,
        Update,
        Delete
    };

    explicit BaseModel(QObject *parent = 0);
    virtual ~BaseModel();

    QSharedPointer<Achievement> createAchievement();
    QSharedPointer<Action> createAction(const QString& uuid);
    //ItemPtr item(const QUuid&) const;

public slots:
    void setAchievementValue(const QString& uuid, int role, const QVariant& value);
    void setActionValue(const QString& uuid, int role, const QVariant& value);

signals:
    void achievementCreated(QSharedPointer<Achievement> achievement);
    void actionCreated(QSharedPointer<Action> action);

    void achievementValueChanged(const QString& uuid, int role, const QVariant& value);
    void actionValueChanged(const QString& uuid, int role, const QVariant& value);

    //void changed(int op, const QList<model::Item*>&);
private:
    struct Private;
    QScopedPointer<Private> m_pvt;

};

} // namespace model


#endif // BASEMODEL_H
