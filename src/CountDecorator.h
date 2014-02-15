//
//  CountDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 16/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef sem15_2_CountDecorator_h
#define sem15_2_CountDecorator_h

#include "Declarations.h"
#include "BaseDecorator.h"

class CountDecorator: public IEnumerable
{
public:
    
    CountDecorator(enum_ptr base): m_base(base), m_result(0)
    {
        try
        {
            while(true)
            {
                m_base->next();
                ++m_result;
            }
        }
        catch (std::exception) {}
    }
    
    virtual int next()
    {
        return m_result;
    }
    
private:
    enum_ptr m_base;
    int m_result;
};

#endif
