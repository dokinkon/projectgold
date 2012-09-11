/*
 * root.cpp
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#include "root.h"
#include <QGraphicsPolygonItem>


namespace model {

Root::Root() {
	// TODO Auto-generated constructor stub

}

Root::~Root() {
	// TODO Auto-generated destructor stub
}

QGraphicsRectItem* Root::addAchivement( QString input )
{
	achivements.push_back( AchivementPtr( new Achivement(input)) );

	QGraphicsRectItem* polygon = new QGraphicsRectItem();
	return polygon;
}

} /* namespace model */
