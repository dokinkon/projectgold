/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIEVEMENT_H_
#define ACHIEVEMENT_H_

#include "item.h"
#include <QString>
#include "model/action.h"


namespace model {

class Achievement;
typedef SHARED_PTR(Achievement) AchievementPtr;

class Achievement: public model::Item
{
public:
    Achievement( QString input )
    {
        setText( input );
    }
    virtual ~Achievement()
    {
    }

    virtual int type() const;

    ActionPtr addAction(QString input)
    {
        ActionPtr act = ActionPtr( new Action(input) );
        m_actions.push_back(  act );

        return act;
    }

private:
    std::vector<model::ActionPtr>		m_actions;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
