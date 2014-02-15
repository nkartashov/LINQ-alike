//
//  SelectDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 16/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef sem15_2_SelectDecorator_h
#define sem15_2_SelectDecorator_h

#include "Declarations.h"
#include "BaseDecorator.h"

class SelectDecorator: public IEnumerable
{
public:
    
    SelectDecorator(enum_ptr base, select_function func): m_base(base), m_func(func) {}
    
    virtual int next()
    {
        return m_func(m_base->next());
    }
    
private:
    enum_ptr m_base;
    select_function m_func;
};

#endif