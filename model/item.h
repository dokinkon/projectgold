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

namespace model {

enum {
    AchievementType,
    ActionType
} Type;

class Item : public QObject
{
    Q_OBJECT
public:
    enum {
        kAchievement,
        kAction,
    } Type;

    QString text() const;
    void setText(const QString&);

    virtual int type() const = 0;

protected:
    QString m_text;
};

} /* namespace model */
#endif 
