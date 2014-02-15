//
//  Declarations.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef sem15_2_Declarations_h
#define sem15_2_Declarations_h

#include <memory>
#include <vector>
#include <functional>

class IEnumerable;
class BaseDecorator;

using std::vector;
using std::shared_ptr;
using std::function;

typedef vector<int>::const_iterator int_iter;
typedef function<int(int)> select_function;
typedef function<bool(int)> where_predicate;
typedef shared_ptr<IEnumerable> enum_ptr;

#endif
