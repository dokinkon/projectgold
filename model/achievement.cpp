#include "model/achievement.h"
#include "model/action.h"

namespace model {

Achievement::Achievement(const QString& input )
{
    setText( input );
}

Achievement::~Achievement()
{
}

int Achievement::type() const
{
    return AchievementType;
}

ActionPtr Achievement::addAction(const QString& input)
{
    ActionPtr act = ActionPtr(new Action(input));
    m_actions.push_back(act);
    return act;
}

} // namespace model
