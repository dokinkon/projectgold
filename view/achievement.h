/*
 * Achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef _VIEW_ACHIVEMENT_H_
#define _VIEW_ACHIVEMENT_H_

#include "view/item.h"
#include "model/achievement.h"
#include "model/action.h"

namespace view {

struct Achievement : public Item
{
    Achievement(  model::AchievementPtr data )
        : Item( data )
    {
        m_achievement_data = data;
    }

    model::AchievementPtr data()
    {
        return m_achievement_data;
    }

    //int type() const;

    private:
    model::AchievementPtr	m_achievement_data;

};

} /* namespace view */

#endif /* ACHIVEMENT_H_ */
