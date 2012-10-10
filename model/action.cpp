#include "action.h"

namespace model {


struct Action::Private
{
    Achievement* achievement;
    QString people;
    int money;
    int time;

    Private()
        : achievement(NULL)
    {
    }
};

Action::Action( QString input, Achievement* achievement )
    : m_pvt(new Private)
{
    m_pvt->achievement = achievement;
    setText( input );
}
Action::~Action()
{
    delete m_pvt;
}

int Action::type() const
{
    return Item::kAction;
}

Achievement* Action::achievement() const
{
    return m_pvt->achievement;
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

void Action::addDependence(ActionPtr)
{

}
void Action::removeDependence(ActionPtr)
{

}


} // namespace model
