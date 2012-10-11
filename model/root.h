/*
 * root.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ROOT_H_
#define ROOT_H_
#include "global.h"
#include "model/achivement.h"
#include <vector>
#include <string>
#include <QString>
#include <QtGui>

namespace model {

struct Root
{
	AchivementPtr addAchivement(QString input)
	{
		AchivementPtr ach = AchivementPtr( new Achivement(input));
		m_achivements.push_back(  ach );

		return ach;
	}

    void deleteAchivement(AchivementPtr);

	std::vector<AchivementPtr> m_achivements;
};

typedef SHARED_PTR(Root) RootPtr;

} /* namespace model */
#endif /* ROOT_H_ */
