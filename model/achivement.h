/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIVEMENT_H_
#define ACHIVEMENT_H_

#include "base.h"
#include <QString>



namespace model {

class Achivement;
typedef SHARED_PTR(Achivement) AchivementPtr;

class Achivement: public model::base {
public:
	Achivement( QString input="");
	virtual ~Achivement();

	QString title;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
