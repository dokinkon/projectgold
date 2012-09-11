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

struct Root {
public:
	Root();
	virtual ~Root();

	QGraphicsRectItem* addAchivement(QString input);

	std::vector<AchivementPtr> achivements;
};

typedef SHARED_PTR(Root) RootPtr;

} /* namespace model */
#endif /* ROOT_H_ */
