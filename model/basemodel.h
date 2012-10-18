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

    QSharedPointer<Achievement> achievement(const QString& uuid) const;
    QSharedPointer<Action> action(const QString& uuid) const;

public slots:
    void setAchievementValue(const QString& uuid, int role, const QVariant& value);
    void setActionValue(const QString& uuid, int role, const QVariant& value);

signals:
    void achievementCreated(QSharedPointer<model::Achievement>);
    void actionCreated(QSharedPointer<model::Action>);

    void achievementValueChanged(const QString& uuid, int role, const QVariant& value);
    void actionValueChanged(const QString& uuid, int role, const QVariant& value);

private:
    struct Private;
    QScopedPointer<Private> m_pvt;

};

} // namespace model


#endif // BASEMODEL_H
