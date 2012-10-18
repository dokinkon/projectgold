#include "model/achievement.h"
#include "model/action.h"
#include <QList>

namespace model {

struct Achievement::Private
{
    QList<QWeakPointer<Action> > m_actions;
};

Achievement::Achievement(const QString& text, const QUuid& uuid)
    : Item(uuid)
    , m_pvt(new Private)
{
    setText(text);
}

Achievement::~Achievement()
{
}

int Achievement::type() const
{
    return AchievementType;
}

void Achievement::addAction(QSharedPointer<Action> actionPtr)
{
    if (!m_pvt->m_actions.contains(actionPtr.toWeakRef())) {
        m_pvt->m_actions << actionPtr.toWeakRef();
    }
}

} // namespace model
