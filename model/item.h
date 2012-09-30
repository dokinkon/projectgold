/*
 * base.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef BASE_H_
#define BASE_H_
#include "global.h"
#include <QString>

namespace model {

class Item;
typedef SHARED_PTR(Item) ItemPtr;


struct Item {

	const QString text()	{	return m_text;	}
	void setText( const QString& i )	{	m_text = i;	}

protected:
	QString m_text;
};

} /* namespace model */
#endif /* BASE_H_ */
