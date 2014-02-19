//
//  main.cpp
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;

#include "IEnumerable.h"


template<class T>
class shmector
{
public:
	void push_back(T t) {}
	typedef const T* const_iterator;
};


int main(int argc, const char * argv[])
{
		std::cout << "First test" << std::endl;	
    try
    {
        vector<int> test;
        test.push_back(10);
        test.push_back(5);
        test.push_back(9);
        test.push_back(7);
        test.push_back(6);
        test.push_back(1);
        auto odd_predicate = [](int x){return x % 2 == 1;};
        auto x2 = [](int x){return x * 2;};
        auto test2 = Do<int, vector<int> >(test)->where(odd_predicate)->select(x2);
        while(true)
        {
            std::cout << test2->next() << std::endl;
        }
    }
    catch (std::exception)
    {
    }
   
		std::cout << "Second test" << std::endl;
    vector<int> test;
    test.push_back(10);
    test.push_back(5);
    test.push_back(9);
    test.push_back(7);
    test.push_back(6);
    test.push_back(1);
    test.push_back(2);
    auto even_predicate = [](int x){return x % 2 == 1;};
    std::cout << Do<int, vector<int> >(test)->where(even_predicate)->count() << std::endl;

    return 0;
}

