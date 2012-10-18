#include "basemodel.h"
#include "model/action.h"
#include "root.h"

#include <QtCore>

namespace model {

struct BaseModel::Private
{
    QMap<QString, QSharedPointer<Achievement> > m_achievements;
    QMap<QString, QSharedPointer<Action> > m_actions;
};

BaseModel::BaseModel(QObject *parent)
    : QObject(parent)
    , m_pvt(new Private)
{
}

BaseModel::~BaseModel()
{
}

QSharedPointer<Achievement> BaseModel::createAchievement()
{
    QSharedPointer<Achievement> achivementPtr(new Achievement(tr("[no name achievement]")));
    m_pvt->m_achievements[achivementPtr->uuid().toString()] = achivementPtr;
    emit achievementCreated(achivementPtr);
    return achivementPtr;
}

QSharedPointer<Action> BaseModel::createAction(const QString& uuid)
{
    if (!m_pvt->m_achievements.contains(uuid)) {
        qDebug() << "no such achievement: " << uuid;
        return QSharedPointer<Action>();
    }

    QSharedPointer<Achievement> achievementPtr = m_pvt->m_achievements[uuid];
    QSharedPointer<Action> actionPtr(new Action(tr("[no name action]"), achievementPtr)); //= achivementPtr->addAction(tr("no name action"));
    achievementPtr->addAction(actionPtr);

    m_pvt->m_actions[actionPtr->uuid().toString()] = actionPtr;
    emit actionCreated(actionPtr);
    return actionPtr;
}

QSharedPointer<Achievement> BaseModel::achievement(const QString& uuid) const
{
    if (!m_pvt->m_achievements.contains(uuid)) {
        return QSharedPointer<Achievement>();
    }
    return m_pvt->m_achievements[uuid];
}

QSharedPointer<Action> BaseModel::action(const QString& uuid) const
{
    if (!m_pvt->m_actions.contains(uuid)) {
        return QSharedPointer<Action>();
    }
    return m_pvt->m_actions[uuid];
}

void BaseModel::setAchievementValue(const QString& uuid, int role, const QVariant& value)
{
    QSharedPointer<Achievement> achievementPtr = m_pvt->m_achievements[uuid];
    if (achievementPtr.isNull()) {
        qDebug() << "[MODEL]: no such achievement: " << uuid;
        return;
    }


    if (achievementPtr->text()!=value.toString()) {
        //qDebug() << "setAchievementValue: " << value.toString();
        achievementPtr->setText(value.toString());
        emit achievementValueChanged(uuid, role, value);
    }
}

void BaseModel::setActionValue(const QString& uuid, int role, const QVariant& value)
{
    QSharedPointer<Action> actionPtr = m_pvt->m_actions[uuid];
    if (actionPtr.isNull()) {
        qDebug() << "[MODEL]: no such action: " << uuid;
    }

    if (actionPtr->text()!=value.toString()) {
        //qDebug() << "setActionValue: " << value.toString();
        actionPtr->setText(value.toString());
        emit actionValueChanged(uuid, role, value);
    }
}

} // namespace model














