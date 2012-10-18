/*
 * action.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "model/item.h"
#include <QScopedPointer>
#include <QSharedPointer>
#include <QWeakPointer>

namespace model {


class Action: public model::Item 
{
    Q_OBJECT
public:
	Action(const QString& text, QSharedPointer<Achievement>, const QUuid& uuid = QUuid());
	virtual ~Action();
    virtual int type() const;

    QWeakPointer<Achievement> achievement() const;

    void setPeople(const QString&);
    QString people() const;

    void setMoney(int);
    int money() const;

    void setTime(int);
    int time() const;

    //void addDependence(ActionPtr);
    //void removeDependence(ActionPtr);

private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

} /* namespace model */
#endif /* ACTION_H_ */
