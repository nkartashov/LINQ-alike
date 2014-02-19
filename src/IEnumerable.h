//
//  IEnumerable.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef __sem15_2__IEnumerable__
#define __sem15_2__IEnumerable__

#include <vector>
#include <functional>
#include <memory>

using std::enable_shared_from_this;
using std::function;
using std::shared_ptr;


template <class T, class container>
class IEnumerable: public enable_shared_from_this<IEnumerable<T, container> >
{
public:
    typedef typename container::const_iterator obj_iter;
    typedef function<T(T)> select_function;
    typedef function<bool(T)> where_predicate;
    typedef shared_ptr<IEnumerable<T, container> > enum_ptr;
    
    virtual T next() = 0;
    enum_ptr where(where_predicate pred);
    enum_ptr select(select_function func);
    int count();
    
    virtual ~IEnumerable() {}
};

template <class T, class container>
typename IEnumerable<T, container>::enum_ptr Do(container const & v);

#include "IEnumerable-impl.h"

#endif /* defined(__sem15_2__IEnumerable__) */
