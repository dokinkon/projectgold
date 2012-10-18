/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIEVEMENT_H_
#define ACHIEVEMENT_H_

#include "model/item.h"
#include <QSharedPointer>
#include <QScopedPointer>

namespace model {


class Achievement: public model::Item
{
public:
    Achievement(const QString& text = QString(), const QUuid& uuid = QUuid());
    virtual ~Achievement();

    int type() const;

    void addAction(QSharedPointer<Action>);

private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
