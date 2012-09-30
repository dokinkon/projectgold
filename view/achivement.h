/*
 * Achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef _VIEW_ACHIVEMENT_H_
#define _VIEW_ACHIVEMENT_H_

#include <view/item.h>
#include <model/achivement.h>
#include <model/action.h>

namespace view {

struct Achivement : public Item
{

	Achivement(  model::AchivementPtr data )
		: Item( data )
	{
		p_achivement_data = data;
	}

	model::AchivementPtr data()
	{
		return p_achivement_data;
	}

private:
	model::AchivementPtr	p_achivement_data;

};

} /* namespace view */
#endif /* ACHIVEMENT_H_ */
