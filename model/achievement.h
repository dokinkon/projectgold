/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIEVEMENT_H_
#define ACHIEVEMENT_H_

#include "model/item.h"
//#include "model/action.h"
//#include "fwdeclaration.h"


namespace model {


class Achievement: public model::Item
{
public:
    Achievement(const QString& input);
    virtual ~Achievement();

    int type() const;

    ActionPtr addAction(const QString& input);

private:
    std::vector<model::ActionPtr> m_actions;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
