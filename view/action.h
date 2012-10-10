/*
 * Achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef _VIEW_ACTION_H_
#define _VIEW_ACTION_H_

#include <view/item.h>
#include <model/action.h>

namespace view {

struct Action : public Item
{

	Action(  model::ActionPtr data )
		: Item( data )
	{
		p_action_data = data;
	}
	model::ActionPtr data()
	{
		return p_action_data;
	}

    int type() const
    {
        return kAction;
    }

private:
	model::ActionPtr	p_action_data;
};

} /* namespace view */
#endif /* Action_H */
