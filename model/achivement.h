/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIVEMENT_H_
#define ACHIVEMENT_H_

#include "item.h"
#include <QString>
#include "model/action.h"


namespace model {

class Achivement;
typedef SHARED_PTR(Achivement) AchivementPtr;

struct  Achivement: public model::Item {

	Achivement( QString input )
	{
		setText( input );
	}
	virtual ~Achivement()
	{
	}

	ActionPtr addAction(QString input)
	{
		ActionPtr act = ActionPtr( new Action(input) );
		m_actions.push_back(  act );

		return act;
	}


	std::vector<model::ActionPtr>		m_actions;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
