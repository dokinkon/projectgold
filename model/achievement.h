/*
 * achivement.h
 *
 *  Created on: 2012/9/11
 *      Author: maple
 */

#ifndef ACHIVEMENT_H_
#define ACHIVEMENT_H_

#include "item.h"
#include <QString>
#include "model/action.h"


namespace model {

class Achivement;
typedef SHARED_PTR(Achivement) AchivementPtr;

class Achivement: public model::Item
{
public:
    Achivement( QString input )
    {
        setText( input );
    }
    virtual ~Achivement()
    {
    }

    virtual int type() const;

    ActionPtr addAction(QString input)
    {
        ActionPtr act = ActionPtr( new Action(input) );
        m_actions.push_back(  act );

        return act;
    }

private:
    std::vector<model::ActionPtr>		m_actions;
};

} /* namespace model */
#endif /* ACHIVEMENT_H_ */
