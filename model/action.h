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


class Action: public model::Item 
{
    Q_OBJECT
public:
	Action(const QString& input, Achievement* achievement = 0);
	virtual ~Action();
    virtual int type() const;

    Achievement* achievement() const;

    void setPeople(const QString&);
    QString people() const;

    void setMoney(int);
    int money() const;

    void setTime(int);
    int time() const;

    void addDependence(ActionPtr);
    void removeDependence(ActionPtr);

private:
    struct Private;
    Private* m_pvt;
};

} /* namespace model */
#endif /* ACTION_H_ */
