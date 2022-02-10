#pragma once
#include <iostream>


template <class T>
class IComparer {
    public:
        virtual int compareTo(T obj1, T obj2) = 0;
};