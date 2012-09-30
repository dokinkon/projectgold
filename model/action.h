/*
 * action.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "item.h"

namespace model {

class Action;
typedef SHARED_PTR(Action) ActionPtr;


struct Action: public model::Item {
	Action( QString input )
	{
		setText( input );
	}
	virtual ~Action()
	{
	}
};

} /* namespace model */
#endif /* ACTION_H_ */
