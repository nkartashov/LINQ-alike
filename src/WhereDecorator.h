//
//  SelectDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef __sem15_2__SelectDecorator__
#define __sem15_2__SelectDecorator__

#include "Declarations.h"
#include "BaseDecorator.h"

class WhereDecorator: public IEnumerable
{
public:
    
    WhereDecorator(enum_ptr base, where_predicate pred): m_base(base), m_pred(pred) {}
    
    virtual int next()
    {
        while (true)
        {
            int value = m_base->next();
            if (m_pred(value))
                return value;
        }
    }
    
private:
    enum_ptr m_base;
    where_predicate m_pred;
};

#endif /* defined(__sem15_2__SelectDecorator__) */