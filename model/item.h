/*
 * base.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef __MODEL_ITEM_BASE_H_
#define __MODEL_ITEM_BASE_H_

#include "fwdeclaration.h"
#include <QString>
#include <QObject>
#include <QUuid>

namespace model {

enum Type {
    AchievementType,
    ActionType
};

class Item : public QObject
{
    Q_OBJECT
public:
    Item(const QUuid& uuid = QUuid());
    virtual ~Item();
    QUuid uuid() const;

    QString text() const;
    void setText(const QString&);

    virtual int type() const = 0;

protected:
    QString m_text;
    QUuid m_uuid;
};

} /* namespace model */
#endif 
