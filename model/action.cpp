#include "action.h"

namespace model {


struct Action::Private
{
    QWeakPointer<Achievement> achievementPtr;
    QString people;
    int money;
    int time;

    Private()
    {
    }
};

Action::Action(const QString& input, QSharedPointer<Achievement> achievementPtr, const QUuid& uuid)
    : Item(uuid)
    , m_pvt(new Private)
{
    m_pvt->achievementPtr = achievementPtr.toWeakRef();
    setText(input);
}
Action::~Action()
{
}

int Action::type() const
{
    return ActionType;
}

QWeakPointer<Achievement> Action::achievement() const
{
    return m_pvt->achievementPtr;
}

void Action::setPeople(const QString& people)
{
    m_pvt->people = people;
}

QString Action::people() const
{
    return m_pvt->people;
}

void Action::setMoney(int)
{

}
int Action::money() const
{
    return 0;
}

void Action::setTime(int)
{

}
int Action::time() const
{
    return 0;
}

/*
void Action::addDependence(ActionPtr)
{

}
void Action::removeDependence(ActionPtr)
{

}
*/


} // namespace model
